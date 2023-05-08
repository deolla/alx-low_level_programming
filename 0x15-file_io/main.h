#ifndef _MAIN_H_
#define _MAIN_H_

#define BUF_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);
void print_usage(char *program_name);
void print_error(char *message, char *file_name, int error_code);

/* 100-elf_header.c */

void sho_elf(unsigned char *e_ident);
void sho_magic(unsigned char *e_ident);
void sho_class(unsigned char *e_ident);
void sho_data(unsigned char *e_ident);
void sho_version(unsigned char *e_ident);
void sho_osiABI(unsigned char *e_ident);
void sho_type(unsigned int e_type, unsigned char *e_ident);
void sho_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf_t);
#endif
