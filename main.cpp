#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#define NUM_HOUSE 4
#define NUM_KNOWS 2
#define NUM_STALL 5

using namespace std;

// Audio paths
const string audio_path = "audio/";
const string hpath = audio_path + "houses/";
const string kpath = audio_path + "know/";
const string spath = audio_path + "stalling/";

class House {
    string housename;
    string houseclip;
public:
    House(string name, string sound) {
        housename = name;
        houseclip = sound;
    }

    string getHouseName() {
        return housename;
    }

    void playKnowClip() {
        sf::SoundBuffer kbuffer;

        // Play know clip
        int kchoice = rand() % (NUM_KNOWS + 1);

        if(kchoice < NUM_KNOWS) {
            switch(kchoice) {
                case 0: kbuffer.loadFromFile(kpath + "iknow.wav"); break;
                case 1: kbuffer.loadFromFile(kpath + "iknowjustwhattodo.wav"); break;
            }

            sf::Sound ksound(kbuffer);
            ksound.play();
        
            while(ksound.getStatus() == sf::Sound::Playing) {
                sf::sleep(sf::milliseconds(100));
                cout << "\rPlaying know clip... " << ksound.getPlayingOffset().asSeconds() << " sec ";
            }
        }
        sf::sleep(sf::milliseconds(500));
    }

    void playStallClip() {
        sf::SoundBuffer sbuffer;
        // Play stall clip
        int schoice = rand() % NUM_STALL;

        if(schoice < NUM_STALL) {
            switch(schoice) {
                case 0: sbuffer.loadFromFile(spath + "ahright.wav"); break;
                case 1: sbuffer.loadFromFile(spath + "difficult.wav"); break;
                case 2: sbuffer.loadFromFile(spath + "itsallhere.wav"); break;
                case 3: sbuffer.loadFromFile(spath + "rightok.wav"); break;
                case 4: sbuffer.loadFromFile(spath + "wheretoputyou.wav"); break;
            }

            sf::Sound ssound(sbuffer);
            ssound.play();
            while(ssound.getStatus() == sf::Sound::Playing) {
                sf::sleep(sf::milliseconds(100));
                cout << "\rPlaying stall clip... " << ssound.getPlayingOffset().asSeconds() << " sec ";
            }
        }
        sf::sleep(sf::milliseconds(500));
    }

    void playHouseClip() {
        sf::SoundBuffer hbuffer;
        // Play house clip
        if(!hbuffer.loadFromFile(houseclip))
            return;

        sf::Sound sound(hbuffer);
        sound.play();

        while(sound.getStatus() == sf::Sound::Playing) {
            sf::sleep(sf::milliseconds(100));
            cout << "\rPlaying house clip... " << sound.getPlayingOffset().asSeconds() << " sec ";
            cout << flush;
        }
        cout << endl;
        
    }

    void playSound() {
        playStallClip();
        playKnowClip();
        playHouseClip();
    }
};

int main() {
    House* house;

    // Choose house for user
    srand(time(NULL)); 
    int choice = rand() % 4;

    switch(choice) {
        case 0: house = new House("Gryffindor", hpath + "gryffindor.wav");    break;
        case 1: house = new House("Slytherin", hpath + "slytherin.wav");     break;
        case 2: house = new House("Hufflepuff", hpath + "hufflepuff.wav");    break;
        case 3: house = new House("Ravenclaw", hpath + "ravenclaw.wav");     break;
    }

    house->playSound();

    while(true) {
        if(sf::Event::KeyPressed) {
            cout << "yes" << endl;
        }
        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            cout << "Q pressed!" << endl;
            break;
        }*/
    }
}
