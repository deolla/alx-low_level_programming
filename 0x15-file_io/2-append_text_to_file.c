#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of file.
 * @text_content: terminated string.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ff;
	ssize_t pop_w = 0;

	if (filename == NULL)
		return (-1);

	ff = open(filename, O_WRONLY | O_APPEND);
	if (ff == -1)
		return (-1);

	if (text_content != NULL)
	{
		pop_w = write(ff, text_content, strlen(text_content));
		if (pop_w == -1)
		{
			close(ff);
			return (-1);
		}
	}

	close(ff);
	return (1);

}
