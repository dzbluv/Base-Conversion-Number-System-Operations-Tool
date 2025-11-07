#include "projectfunctions.h"

int main() {
    printf("\033[4;90mthis code was created by : Adjeroud Mohamed Mounib and Belhoul Amine .\033[0m\n");
    printf("\033[36m================================================\n================\033[0m   WELCOME TO   \033[36m================\n================================================\033[0m\n");
    printf(
        "\033[95m _     _____                           _        \n"
        "| |   /  __ \\                         | |       \n"
        "| |__ | /  \\/ ___  _ ____   _____ _ __| |_ ___  \n"
        "| '_ \\| |    / _ \\| '_ \\ \\ / / _ \\ '__| __/ _ \\ \n"
        "| |_) | \\__/\\ (_) | | | \\ V /  __/ |  | || (_) |\n"
        "|_.__/ \\____/\\___/|_| |_|\\_/ \\___|_|   \\__\\___/ \n"
        "                                                \033[0m\n"
    );
    printf("\033[36m================================================\033[0m\n       Your Base Conversion Tool Awaits!     \n\033[36m================================================\033[0m\n");
    mainlist:
    int action;
    printf("\n\033[36m------------------------------------------------\033[0m\n                Choose an Action               \n\033[36m------------------------------------------------\033[0m\n");
    printf("  [1] Base Conversion\n  [2] Conversion between (s+av, rc, tc)\n  [3] Exit\n\033[36m------------------------------------------------\033[0m\n");
    printf("Enter the number of your action: ");
    scanf("%d", &action);
    system("cls");
    switch (action) {
        case 1: {
        system("cls");  // Clear console
        printf("\033[36m=============\033[0m   Base Conversion   \033[36m=============\033[0m\n");
        char number[100], output[100];
        int input_base, output_base;
        baseconversion:  // Restart point
        printf(" [ ] Enter the number to convert: ");
        scanf("%s", number);
        printf(" [ ] Enter the base of the input number (2, 8, 10, 16): ");
        if (scanf("%d", &input_base) != 1 || (input_base != 2 && input_base != 8 && input_base != 10 && input_base != 16)) {
            printf(" [X] \033[31mError\033[0m: Invalid base. Choose 2, 8, 10, or 16.\n");
            while (getchar() != '\n');  // Clear the input buffer
            printf(" [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n");
            int choice;
            if (scanf("%d", &choice) != 1) return 0;
            if (choice == 1) { system("cls"); goto mainlist; }
            else if (choice == 2) goto baseconversion;
            else return 0;
        }
        if (check_valid(number, input_base)) {  // Invalid input for base
            printf(" [X] \033[31mError\033[0m: Invalid number for base %d.\n [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n", input_base);
            int choice;
            if (scanf("%d", &choice) != 1) return 0;
            if (choice == 1) { system("cls"); goto mainlist; }
            else if (choice == 2) goto baseconversion;
            else return 0;
        }
        printf(" [ ] Enter the desired output base (2, 8, 10, 16): ");
        if (scanf("%d", &output_base) != 1 || (output_base != 2 && output_base != 8 && output_base != 10 && output_base != 16)) {
            printf(" [X] \033[31mError\033[0m: Invalid base. Choose 2, 8, 10, or 16.\n");
            while (getchar() != '\n');  // Clear the input buffer
            printf(" [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n");
            int choice;
            if (scanf("%d", &choice) != 1) return 0;
            if (choice == 1) { system("cls"); goto mainlist; }
            else if (choice == 2) goto baseconversion;
            else return 0;
        }
        double decimal_value;
        if (input_base == 10)
            decimal_value = atof(number);  // Convert input to decimal
        else
            decimal_value = tob10(number, input_base);
        if (output_base == 10)
            sprintf(output, "%lf", decimal_value);  // Convert decimal value to a string for output
        else
            fromb10(decimal_value, output, output_base);
        printf(" [ ]====>Converted number: \033[35m%s\033[0m<====[ ]\n [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n", output);
        int choice;
        if (scanf("%d", &choice) != 1) return 0;
        if (choice == 1) { system("cls"); goto mainlist; }
        else if (choice == 2) goto baseconversion;
        else return 0;
        }
        break;
        case 2: {
        system("cls");  // Clear the screen for a fresh operations menu
        printf("\033[36m=============\033[0m   Operations Menu   \033[36m=============\033[0m\n");
        int oprt, oprt_base, oprt_bits;
        char output[100], oprt_inp[100];
        // Start of operations menu
        operations_menu:
            printf(" [ ] Choose an operation:\n     [1] s+av\n     [2] rc\n     [3] tc\n [ ] Enter your choice: ");
            // Get operation choice and validate it
            if (scanf("%d", &oprt) != 1 || oprt < 1 || oprt > 3) {
                while (getchar() != '\n');  // Flush input buffer if invalid input
                printf(" [X] \033[31mError\033[0m: Invalid operation.\n [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n");
                int choice; scanf("%d", &choice);  // Get user's choice for what to do next
                if (choice == 1) { system("cls"); goto mainlist; }  // Return to main menu
                else if (choice == 2) goto operations_menu;  // Restart operations menu
                else return 0;  // Exit the program
            }
            // Get the base of the number and validate it
            printf(" [ ] Enter the base of the number (2, 8, 10, 16): ");
            if (scanf("%d", &oprt_base) != 1 || (oprt_base != 2 && oprt_base != 8 && oprt_base != 10 && oprt_base != 16)) {
                while (getchar() != '\n');  // Flush input buffer if invalid input
                printf(" [X] \033[31mError\033[0m: Invalid base.\n [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n");
                int choice; scanf("%d", &choice);  // Get user's choice for what to do next
                if (choice == 1) { system("cls"); goto mainlist; }  // Return to main menu
                else if (choice == 2) goto operations_menu;  // Restart operations menu
                else return 0;  // Exit the program
            }
            // Get the input number
            printf(" [ ] Enter the number: ");
            scanf("%s", oprt_inp);
            // Check if the entered number is valid for the given base
            if (check_valid(oprt_inp, oprt_base)) {
                printf(" [X] \033[31mError\033[0m: Invalid number for base %d.\n [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n", oprt_base);
                int choice; scanf("%d", &choice);  // Get user's choice for what to do next
                if (choice == 1) { system("cls"); goto mainlist; }  // Return to main menu
                else if (choice == 2) goto operations_menu;  // Restart operations menu
                else return 0;  // Exit the program
            }
            // Convert the number to binary based on its base
            double oprt_intd = atof(oprt_inp);  // Convert input string to double
            char oprt_bin[100];  // Buffer for binary representation
            if (oprt_base == 2) strcpy(oprt_bin, oprt_inp);  // If already binary, copy directly
            else if (oprt_base == 8 || oprt_base == 16) fromb10(tob10(oprt_inp, oprt_base), oprt_bin, 2);  // Convert from octal/hex to binary
            else fromb10(oprt_intd, oprt_bin, 2);  // Convert decimal to binary
            printf(" [ ] Number in binary: \033[34m%s\033[0m\n", oprt_bin);  // Display the binary number
            // Get the number of bits required for representation
            printf(" [ ] Enter the number of bits: ");
            scanf("%d", &oprt_bits);
            // Calculate the minimum bits required to represent the number
            int min_bits_required = (int)(log10(fabs(atof(oprt_bin)))) + 2;
            // Check if the number of bits is sufficient
            if (oprt_bits < min_bits_required) {
                printf(" [X] \033[31mError\033[0m: Insufficient bits. Minimum required: %d.\n [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n", min_bits_required);
                int choice; scanf("%d", &choice);  // Get user's choice for what to do next
                if (choice == 1) { system("cls"); goto mainlist; }  // Return to main menu
                else if (choice == 2) goto operations_menu;  // Restart operations menu
                else return 0;  // Exit the program
            }
            // Perform the selected operation
            if (oprt == 1) {
                sav(oprt_bin, oprt_bits, output);  // Perform s+av operation
                printf(" [ ] Result (s+av): \033[32m%s\033[0m\n", output);
            }
            else if (oprt == 2) {
                sav(oprt_bin, oprt_bits, output);  // Perform s+av operation before rc
                rc(output);  // Perform rc operation
                printf(" [ ] Result (rc): \033[32m%s\033[0m\n", output);
            }
            else if (oprt == 3) {
                sav(oprt_bin, oprt_bits, output);  // Perform s+av operation before tc
                tc(output);  // Perform tc operation
                printf(" [ ] Result (tc): \033[32m%s\033[0m\n", output);
            }
            // Ask user if they want to continue or exit
            printf(" [ ] choose an option:\n     [1] Main menu\n     [2] Restart\n     [3] Exit\n\n");
            int restart_choice; scanf("%d", &restart_choice);
            if (restart_choice == 1) { system("cls"); goto mainlist; }  // Go back to main menu
            else if (restart_choice == 2) goto operations_menu;  // Restart operations menu
            else return 0;  // Exit the program
    }break;
        case 3: {
            printf("Exiting the program.\n");
            return 0;  // Exit the program
        }
        default:
            printf(" [X] \033[31mError\033[0m: Invalid action number.\n");
            goto mainlist;
    }
    return 0;
}
