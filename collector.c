//
// Created by Ahmet Kotan on 15.02.2020.
// https://gist.github.com/ahmetkotan/a53c9528401dd841dd57e6df08da3919
//

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <elf.h>
#include <assert.h>
#include <glib.h>

int
check_test_function_name (const char *name) {
    char *base = "test_";
    for (int i = 0; i < 5; i++) {
        if (base[i] != name[i])
            return 0;
    }

    return 1;
}

GSList *
collect_test_functions (char *filename) {
    FILE *file = fopen(filename, "r");

    if (fseek(file, 0, SEEK_END)) {
        fclose(file);
        return NULL;
    }
    long file_size = ftell(file);
    void *load_bytes = mmap(NULL, (size_t)file_size, PROT_READ, MAP_PRIVATE,
                            fileno(file), 0);
    fclose(file);

    Elf64_Ehdr elf_hdr;
    memmove(&elf_hdr, load_bytes, sizeof(elf_hdr));

    char *cbytes = (char *)load_bytes;

    size_t dynstr_off = 0;
    size_t dynsym_off = 0;
    size_t dynsym_sz = 0;

    for (uint16_t i = 0; i < elf_hdr.e_shnum; i++) {
        size_t offset = elf_hdr.e_shoff + i * elf_hdr.e_shentsize;
        Elf64_Shdr shdr;
        memmove(&shdr, load_bytes + offset, sizeof(shdr));
        switch (shdr.sh_type) {
            case SHT_SYMTAB:
            case SHT_STRTAB:
                if (!dynstr_off) {
                    dynstr_off = shdr.sh_offset;
                }
                break;
            case SHT_DYNSYM:
                dynsym_off = shdr.sh_offset;
                dynsym_sz = shdr.sh_size;
                break;
            default:
                break;
        }
    }
    assert(dynstr_off);
    assert(dynsym_off);

    GSList *function_list = NULL;
    for (size_t j = 0; j * sizeof(Elf64_Sym) < dynsym_sz; j++) {
        Elf64_Sym sym;
        size_t absoffset = dynsym_off + j * sizeof(Elf64_Sym);
        memmove(&sym, cbytes + absoffset, sizeof(sym));

        if (sym.st_name != 0) {
            const char *func_name = cbytes + dynstr_off + sym.st_name;
            if (check_test_function_name(func_name))
                function_list = g_slist_append(function_list, (char *)func_name);
        }
    }

    return function_list;
}
