#include <iostream>
#include "PhotoRobotAF.h"

int main() {
	setlocale(LC_ALL, "Ukr");

    // Вибираємо фабрику "Female""Male"  vv
    PhotoRobotFactory* factory = CreateMaleFactory();

    Eyes* eyes = factory->createEyes();
    Nose* nose = factory->createNose();
    Mouth* mouth = factory->createMouth();

    std::cout << "Фоторобот:\n";
    std::cout << "- " << eyes->draw() << "\n";
    std::cout << "- " << nose->draw() << "\n";
    std::cout << "- " << mouth->draw() << "\n";

    DestroyEyes(eyes);
    DestroyNose(nose);
    DestroyMouth(mouth);
    DestroyFactory(factory);

    return 0;
}