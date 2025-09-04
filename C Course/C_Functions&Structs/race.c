#include <unistd.h>   // write
#include <stdlib.h>   // rand, srand
#include <time.h>     // time

// =========================
//      I/O helpers 
// =========================
static size_t my_strlen(const char* s) {
    size_t n = 0; if (!s) return 0; while (s[n]) ++n; return n;
}

static void my_write(const char* s) {
    if (!s) return;
    write(1, s, my_strlen(s));
}

static void my_write_int(int n) {
    char buf[12];
    int i = 0;
    if (n == 0) { write(1, "0", 1); return; }
    if (n < 0) { write(1, "-", 1); n = -n; }
    while (n > 0 && i < (int)sizeof(buf)) { buf[i++] = (char)('0' + (n % 10)); n /= 10; }
    while (--i >= 0) write(1, &buf[i], 1);
}

// =========================
// structures section
// =========================
struct Race {
    int numberOfLaps;
    int currentLap;
    const char* firstPlaceDriverName;
    const char* firstPlaceRaceCarColor;
};

struct RaceCar {
    const char* driverName;
    const char* raceCarColor;
    int totalLapTime;
};

// =========================
// print functions section
// =========================
static void printIntro(void) {
    my_write("Welcome to our main event digital race fans!\n");
    my_write("I hope everybody has their snacks because we are about to begin!\n\n");
}

static void printCountDown(void) {
    my_write("Racers Ready! In...\n");
    my_write("5\n4\n3\n2\n1\n");
    my_write("Race!\n\n");
}

static void printFirstPlaceAfterLap(const struct Race* race) {
    my_write("After lap number ");
    my_write_int(race->currentLap);
    my_write("\n");

    my_write("First Place Is: ");
    my_write(race->firstPlaceDriverName);
    my_write(" in the ");
    my_write(race->firstPlaceRaceCarColor);
    my_write(" race car!\n\n");
}

static void printCongratulation(const struct Race* race) {
    my_write("Let's all congratulate ");
    my_write(race->firstPlaceDriverName);
    my_write(" in the ");
    my_write(race->firstPlaceRaceCarColor);
    my_write(" race car for an amazing performance.\n");
    my_write("It truly was a great race and everybody have a goodnight!\n");
}

// =========================
// logic functions section
// =========================
static int calculateTimeToCompleteLap(void) {
    int speed = (rand() % 3) + 1;        // 1..3
    int acceleration = (rand() % 3) + 1; // 1..3
    int nerves = (rand() % 3) + 1;       // 1..3
    return speed + acceleration + nerves; // total lap time contribution
}

static void updateRaceCar(struct RaceCar* raceCar) {
    if (!raceCar) return;
    raceCar->totalLapTime += calculateTimeToCompleteLap();
}

static void updateFirstPlace(struct Race* race, struct RaceCar* a, struct RaceCar* b) {
    if (!race || !a || !b) return;
    if (a->totalLapTime <= b->totalLapTime) {
        race->firstPlaceDriverName = a->driverName;
        race->firstPlaceRaceCarColor = a->raceCarColor;
    } else {
        race->firstPlaceDriverName = b->driverName;
        race->firstPlaceRaceCarColor = b->raceCarColor;
    }
}

// =========================
// race orchestration
// =========================
static void startRace(struct RaceCar* a, struct RaceCar* b) {
    struct Race race = {5, 1, "", ""};

    for (int lap = 1; lap <= race.numberOfLaps; ++lap) {
        race.currentLap = lap;
        updateRaceCar(a);
        updateRaceCar(b);
        updateFirstPlace(&race, a, b);
        printFirstPlaceAfterLap(&race);
    }
    printCongratulation(&race);
}

int main(void) {
    srand((unsigned int)time(NULL));

    printIntro();
    printCountDown();

    struct RaceCar car1 = {"George", "yellow", 0};
    struct RaceCar car2 = {"Cosmo", "orange", 0};

    startRace(&car1, &car2);
    return 0;
}
