#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1) {
		long long number = atoll(line);
		long long div = 2;

		while (div * div <= number) {
			if (number % div == 0) {
				printf("%lld=%lld*%lld\n", number, number / div, div);
				break;
			}
			div++;
	        }

		if (div * div > number && number != 1) {
			printf("%lld=%lld*%lld\n", number, number, 1LL);
		}
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
