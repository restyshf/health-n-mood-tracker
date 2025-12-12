#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// =========================
//       STRUCT DATA
// =========================
struct HealthData {
    int steps[7];
    int sleepHours[7];
    int waterIntake[7];
    string mood[7];                   // ➜ Fitur tambahan: mood tracker
} weeklyData;

const int WATER_INTAKE_TARGET = 8;
const int STEP_TARGET = 5000;
const int MIN_SLEEP_TARGET = 7;
const int MAX_SLEEP_TARGET = 9;

// =========================
//   FUNGSI DEKLARASI
// =========================
void showMenu();
void inputData(HealthData &data);
void viewWeeklyStats(const HealthData &data);
void checkRecomendation(const HealthData &data);
void resetData(HealthData &data);
void bestWorstDay(const HealthData &data);   // ➜ Added Feature

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// =========================
//         UI MENU
// =========================
void showMenu() {
    clearScreen();
    cout << "==== MINI HEALTH TRACKER ====\n";
    cout << "1. Input Data\n";
    cout << "2. View Weekly Stats\n";
    cout << "3. Check Health Recommendations\n";
    cout << "4. Reset Data\n";
    cout << "5. Best & Worst Day (Bonus)\n";   // ➜ New Menu
    cout << "6. Exit\n";
}

// =========================
//     INPUT DATA HARIAN
// =========================
void inputData(HealthData &data) {
    int day;
    clearScreen();

    cout << "=== INPUT HEALTH DATA ===\n";
    cout << "Enter day (1–7): ";

    if (!(cin >> day) || day < 1 || day > 7) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    int index = day - 1;

    cout << "Cups of Water Intake: ";
    cin >> data.waterIntake[index];

    cout << "Total Steps: ";
    cin >> data.steps[index];

    cout << "Sleep Hours: ";
    cin >> data.sleepHours[index];

    cout << "Mood today (happy/neutral/sad): ";
    cin >> data.mood[index];

    cout << "\n✔ Data saved!\n";
    cin.ignore();
    cin.get();
}

// =========================
//     TAMPIL STATISTIK
// =========================
void viewWeeklyStats(const HealthData &data) {
    clearScreen();

    cout << "=== WEEKLY HEALTH STATS ===\n";
    cout << "Day |   Water | Steps | Sleep | Mood\n";
    cout << string(55, '-') << endl;

    float totalWater = 0, totalSteps = 0, totalSleep = 0;
    int daysWithData = 0;

    for (int i = 0; i < 7; i++) {
        cout << setw(2) << (i + 1) << " | "
             << setw(7) << data.waterIntake[i] << " | "
             << setw(6) << data.steps[i] << " | "
             << setw(5) << data.sleepHours[i] << " | "
             << setw(7) << (data.mood[i].empty() ? "-" : data.mood[i])
             << endl;

        if (data.waterIntake[i] || data.steps[i] || data.sleepHours[i]) {
            totalWater += data.waterIntake[i];
            totalSteps += data.steps[i];
            totalSleep += data.sleepHours[i];
            daysWithData++;
        }
    }

    cout << string(55, '-') << endl;

    if (daysWithData > 0) {
        cout << "Average Water : " << (totalWater / daysWithData) << endl;
        cout << "Average Steps : " << (totalSteps / daysWithData) << endl;
        cout << "Average Sleep : " << (totalSleep / daysWithData) << endl;
    } else {
        cout << "No data available.\n";
    }

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// =========================
//   CEK REKOMENDASI HEALTH
// =========================
void checkRecomendation(const HealthData &data) {
    clearScreen();

    float totalWater = 0, totalSteps = 0, totalSleep = 0;
    int days = 0;

    for (int i = 0; i < 7; i++) {
        if (data.waterIntake[i] || data.steps[i] || data.sleepHours[i]) {
            totalWater += data.waterIntake[i];
            totalSteps += data.steps[i];
            totalSleep += data.sleepHours[i];
            days++;
        }
    }

    if (days == 0) {
        cout << "No data available. Please input first!";
        cin.ignore();
        cin.get();
        return;
    }

    float avgWater = totalWater / days;
    float avgSteps = totalSteps / days;
    float avgSleep = totalSleep / days;

    cout << "=== RECOMMENDATIONS ===\n";

    // WATER
    cout << "\n1. WATER INTAKE\n";
    cout << "Target: 8 cups/day\n";
    cout << "You: " << avgWater << endl;
    cout << "Status: ";
    if (avgWater >= 8) cout << "Good hydration!\n";
    else cout << (8 - avgWater) << " more cups needed.\n";

    // STEPS
    cout << "\n2. STEPS\n";
    cout << "Target: 5000 steps/day\n";
    cout << "You: " << avgSteps << endl;
    cout << "Status: ";
    if (avgSteps >= 5000) cout << "Great job!\n";
    else if (avgSteps >= 4500) cout << "Almost there.\n";
    else cout << "Increase your activity.\n";

    // SLEEP
    cout << "\n3. SLEEP\n";
    cout << "Target: 7–9 hours/day\n";
    cout << "You: " << avgSleep << endl;
    cout << "Status: ";
    if (avgSleep >= 7 && avgSleep <= 9)
        cout << "Good sleep pattern.\n";
    else if (avgSleep < 7)
        cout << "You need more sleep.\n";
    else
        cout << "You sleep too long.\n";

    cin.ignore();
    cin.get();
}

// =========================
//     RESET DATA
// =========================
void resetData(HealthData &data) {
    clearScreen();
    char confirm;

    cout << "Are you sure? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        for (int i = 0; i < 7; i++) {
            data.steps[i] = 0;
            data.sleepHours[i] = 0;
            data.waterIntake[i] = 0;
            data.mood[i] = "";
        }
        cout << "✔ Data has been reset.\n";
    } else {
        cout << "Cancelled.\n";
    }

    cin.ignore();
    cin.get();
}

// =========================
//   BEST & WORST DAY
// =========================
int scoreDay(int water, int steps, int sleep) {
    int score = 0;

    // water
    if (water >= WATER_INTAKE_TARGET) score += 10;
    else score += (water * 10 / WATER_INTAKE_TARGET);

    // steps
    if (steps >= STEP_TARGET) score += 10;
    else score += (steps * 10 / STEP_TARGET);

    // sleep
    if (sleep >= MIN_SLEEP_TARGET && sleep <= MAX_SLEEP_TARGET) score += 10;

    return score;
}

void bestWorstDay(const HealthData &data) {
    clearScreen();
    
    int bestDay = -1, worstDay = -1;
    int bestScore = -1, worstScore = 999;

    for (int i = 0; i < 7; i++) {
        int sc = scoreDay(data.waterIntake[i], data.steps[i], data.sleepHours[i]);

        if (sc > bestScore) {
            bestScore = sc;
            bestDay = i;
        }
        if (sc < worstScore) {
            worstScore = sc;
            worstDay = i;
        }
    }

    cout << "=== BEST & WORST DAY ===\n";
    cout << "Best Day : Day " << bestDay + 1 << " (Score " << bestScore << ")\n";
    cout << "Worst Day: Day " << worstDay + 1 << " (Score " << worstScore << ")\n";

    cin.ignore();
    cin.get();
}

// =========================
//        MAIN MENU
// =========================
int main() {
    int choice;

    while (true) {
        showMenu();
        cout << "Select: ";
        cin >> choice;

        switch (choice) {
            case 1: inputData(weeklyData); break;
            case 2: viewWeeklyStats(weeklyData); break;
            case 3: checkRecomendation(weeklyData); break;
            case 4: resetData(weeklyData); break;
            case 5: bestWorstDay(weeklyData); break;
            case 6: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}

// ini komentar