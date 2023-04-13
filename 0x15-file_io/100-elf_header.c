#include "main.h"

/**
 * sho_data - print data of ELF.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void sho_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * sho_version - print the version ELF.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void sho_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * sho_osabi - print OS/ABI of ELF.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void sho_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * sho_abi - Prints ABI version of ELF.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void sho_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * sho_type - Prints type of ELF.
 * @e_type: type.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void sho_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * sho_entry - Prints entry point of ELF.
 * @e_entry: address.
 * @e_ident: a pointer.
 *
 * Return: no return.
 */
void sho_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Close an ELF file.
 * @elf_t: The file descriptor of the ELF file.
 *
 * Return: no return.
 */
void close_elf(int elf_t)
{
	if (close(elf_t) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf_t);
		exit(98);
	}
}

/**
 * main - Displays the information containing ELF.
 * @argc: int argument.
 * @argv: char argument.
 *
 * Return: 0 on success.
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int otto, randy;

	otto = open(argv[1], O_RDONLY);
	if (otto == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(otto);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	randy = read(otto, header, sizeof(Elf64_Ehdr));
	if (randy == -1)
	{
		free(header);
		close_elf(otto);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	assess_elf(header->e_ident);
	printf("ELF Header:\n");
	sho_magic(header->e_ident);
	sho_class(header->e_ident);
	sho_data(header->e_ident);
	sho_version(header->e_ident);
	sho_osabi(header->e_ident);
	sho_abi(header->e_ident);
	sho_type(header->e_type, header->e_ident);
	sho_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(otto);
	return (0);
}
