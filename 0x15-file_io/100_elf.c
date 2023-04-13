#include "main.h"

/**
 * assess_elf - check for an elf file.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void assess_elf(unsigned char *e_ident)
{
        int pop_p;

        for ( pop_p = 0; pop_p < 4; pop_p++)
        {
                if (e_ident[pop_p] != 127 &&
                    e_ident[pop_p] != 'E' &&
                    e_ident[pop_p] != 'L' &&
                    e_ident[pop_p] != 'F')
                {
                        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
                        exit(98);
                }
        }
}

/**
 * sho_magic - print magic number of ELF.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void sho_magic(unsigned char *e_ident)
{
        int pop_p;
        printf(" Magic ");

        for (pop_p = 0; pop_p < EI_NIDENT; pop_p++)
        {
                printf("%02x", e_ident[pop_p]);

                if (pop_p == EI_NIDENT - 1)
                        printf("\n");
                else
                        printf(" ");
        }
}

/**
 * sho_class - print status of ELF.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void sho_class(unsigned char *e_ident)
{
        printf("  Class:                             ");

        switch (e_ident[EI_CLASS])
        {
        case ELFCLASSNONE:
                printf("none\n");
                break;
        case ELFCLASS32:
                printf("ELF32\n");
                break;
        case ELFCLASS64:
                printf("ELF64\n");
                break;
        default:
                printf("<unknown: %x>\n", e_ident[EI_CLASS]);
        }
}
