#include <stdio.h>
#include <stdlib.h>

void encryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (!fin || !fout) {
        printf("Error opening file!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key, fout); // XOR encryption
    }

    fclose(fin);
    fclose(fout);

    printf("Encryption completed! Output saved to %s\n", outputFile);
}

void decryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (!fin || !fout) {
        printf("Error opening file!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key, fout); // XOR decryption (same operation)
    }

    fclose(fin);
    fclose(fout);

    printf("Decryption completed! Output saved to %s\n", outputFile);
}

int main() {
    int choice;
    char key;
    char inputFile[100], outputFile[100];

    do {
        printf("\n===== File Encryptor & Decryptor =====\n");
        printf("1. Encrypt File\n");
        printf("2. Decrypt File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Enter input file name: ");
            scanf("%s", inputFile);
            printf("Enter output file name: ");
            scanf("%s", outputFile);
            printf("Enter key character: ");
            scanf(" %c", &key);
        }

        switch (choice) {
            case 1:
                encryptFile(inputFile, outputFile, key);
                break;
            case 2:
                decryptFile(inputFile, outputFile, key);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}

