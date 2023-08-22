#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define COLOR_WHITE "\x1b[37m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RED "\x1b[31m"
#define COLOR_CYAN "\x1b[36m"

void printHelp() {
    printf(COLOR_CYAN "Syntax:\n- check (for your ping)\n- check -w | -website <site url> (to ping a specific website)\n- check -h | -help (for this menu)\n");
}

int main(int argc, char *argv[]) {
    char *website = "google.de";

    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
            printHelp();
        } else {
            printf(COLOR_RED "The command '%s' you typed in is not recognized!\nUse -h or -help for help\n", argv[1]);
        }
    } else if (argc == 3) {
        if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "-website") == 0) {
            website = argv[2];
            char command[100];
            sprintf(command, "ping -c 4 %s > /dev/null 2>&1 > output.txt", website);

            int animation_length = 3;
            const char *animation[] = {COLOR_GREEN "|", COLOR_GREEN "/", COLOR_GREEN "-"};
            for (int i = 0;; i = (i + 1) % animation_length) {
                printf(COLOR_WHITE "\rChecking Ping for '%s' %s", website, animation[i]);
                fflush(stdout);
                usleep(200000);

                system(command);

                if (i == animation_length - 1) {
                    break;
                }
            }

            FILE *file = fopen("output.txt", "r");
            if (file == NULL) {
                perror("Unable to read output!");
                return 1;
            }

            char buffer[100];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                if (strstr(buffer, "rtt")) {
                    printf(COLOR_GREEN "\n%s", buffer);
                }
            }

            fclose(file);
        } else {
            printf(COLOR_RED "The command '%s' you typed in is not recognized!\nUse -h or -help for help\n", argv[1]);
        }
    } else if (argc > 2) {
        printf(COLOR_RED "You typed in too many arguments!\nUse -help for help\n");
    } else {
        char command[100];
        sprintf(command, "ping -c 4 %s > /dev/null 2>&1 > output.txt", website);

        int animation_length = 3;
        const char *animation[] = {COLOR_GREEN "|", COLOR_GREEN "/", COLOR_GREEN "-"};
        for (int i = 0;; i = (i + 1) % animation_length) {
            printf(COLOR_WHITE "\rChecking Ping %s", animation[i]);
            fflush(stdout);
            usleep(200000);

            system(command);

            if (i == animation_length - 1) {
                break;
            }
        }

        FILE *file = fopen("output.txt", "r");
        if (file == NULL) {
            perror("Unable to read output!");
            return 1;
        }

        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            if (strstr(buffer, "rtt") || strstr(buffer, "rtt")) {
                printf(COLOR_GREEN "\n%s", buffer);
            }
        }

        fclose(file);
    }

    return 0;
}