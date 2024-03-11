#include <stdio.h>

// this function takes in a score and prints all the possible combinations of points for the given score
void calculating_scores(int score) {
    const int scr_tdplus2 = 8; // Touchdown with 2-point = 8
    const int scr_tdplus1 = 7; // Touchdown with 1-point = 7
    const int scr_td = 6;      // Touchdown = 6
    const int scr_fg = 3;      // Field Goal without touchdown = 3
    const int scr_safety = 2;  // Safety = 2

    printf("Possible combinations of scoring plays:\n\n");

    // Itarating through the given the standard points defined above and calculating all the possibilites.
    for (int tdPlus2 = 0; tdPlus2 <= score / scr_tdplus2; ++tdPlus2) {
        for (int tdPlus1 = 0; tdPlus1 <= score / scr_tdplus1; ++tdPlus1) {
            for (int td = 0; td <= score / scr_td; ++td) {
                for (int fg = 0; fg <= score / scr_fg; ++fg) {
                    for (int safety = 0; safety <= score / scr_safety; ++safety) {
                        if (tdPlus2 * scr_tdplus2 + tdPlus1 * scr_tdplus1 + td * scr_td +
                            fg * scr_fg + safety * scr_safety == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   tdPlus2, tdPlus1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

// This function takes in a value of score from the user and calls the function defined above.
int main() {
    int score;
    printf("Enter 0 or 1 to STOP.\n\n");
    while (1) {
        printf("\nEnter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Exciting...\n");
            break;
        } else {
            calculating_scores(score);
        }
    }

    return 0;
}