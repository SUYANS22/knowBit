#include "suyans.h"
#include "task.h" 
#include <iostream>
#include <string>

using namespace std;

float calculateCompletionRate(int totalTasks, int completedTasks) {
    if (totalTasks == 0) return 0;
    return (completedTasks * 100.0) / totalTasks;
}

void showProgressBar(float completionRate) {
    int barLength = 20; 
    int filled = (completionRate / 100) * barLength;

    cout << "Progress: [";
    for (int i = 0; i < barLength; i++) {
        if (i < filled) cout << "#";
        else cout << "-";
    }
    cout << "] " << completionRate << "%" << endl;
}

void showBadge(float completionRate, int currentStreak) {
    cout << "Badge Earned: ";
    if (completionRate == 100 && completionRate > 0) cout << "🌟 Perfect Day Badge!" << endl;
    else if (completionRate >= 80) cout << "🔥 Productivity Master!" << endl;
    else if (completionRate >= 50) cout << "👍 Keep Grinding!" << endl;
    else cout << "🌱 Beginner Badge" << endl;
}

void showLevel(int maxStreak) {
    cout << "Level: ";
    if (maxStreak >= 30) cout << "Legend" << endl;
    else if (maxStreak >= 15) cout << "Pro" << endl;
    else if (maxStreak >= 7) cout << "Intermediate" << endl;
    else cout << "Novice" << endl;
}

// int productivityQuiz() {
//     int score = 0;
//     string answer;

//     cout << "\nProductivity Quiz \n";
//     cout << "Answer the questions to earn bonus points!\n\n";

//     cout << "Q1: What is 5 + 7? ";
//     cin >> answer;
//     if (answer == "12") { cout << "Correct!\n"; score += 10; }
//     else cout << " Wrong!\n";

//     cout << "Q2: What is 50+33? ";
//     cin >> answer;
//     if (answer == "83") { cout << "Correct!\n"; score += 10; } 
//     else cout << " Wrong!\n";

//     cout << "Q3: What is 12*12? ";
//     cin >> answer;
//     if (answer == "144") { cout << "Correct!\n"; score += 10; } 
//     else cout << "Wrong!\n";

//     cout << "\n Quiz Finished! You earned " << score << " bonus points.\n";
//     return score;
// }
void displayGamification() {
    int totalTasks = allTasks.size(); 
    int completedTasks = 0;

    for (const auto& t : allTasks) {
        if (t.isCompleted) completedTasks++;
    }
    int currentStreak = 5;
    int maxStreak = 10;

    cout << "\n========== GAMIFICATION STATS ==========\n";
    cout << "Total Tasks:     " << totalTasks << "\n";
    cout << "Completed Tasks: " << completedTasks << "\n\n";

    float rate = calculateCompletionRate(totalTasks, completedTasks);
    
    showProgressBar(rate);
    showBadge(rate, currentStreak);
    showLevel(maxStreak);

    // cout << "\nDo you want to take the Productivity Quiz for bonus points? (y/n): ";
    // char choice;
    // cin >> choice;
    // if (choice == 'y' || choice == 'Y') {
    //     productivityQuiz();
    // }
    cout << "========================================\n";
}