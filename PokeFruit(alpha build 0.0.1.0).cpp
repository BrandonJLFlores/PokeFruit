#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class FRUITS:public sf::Sprite{
public:
    int s;
};

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time);
    void render();
    void handlePlayerInput(sf::Keyboard::Key, bool);
private:
    sf::RenderWindow mWindow;
    sf::Texture mBG;
    sf::Sprite BG;
    sf::Texture mPlayer;
    sf::Sprite Player;
    sf::Texture mlife[4];
    sf::Sprite life[4];
    sf::Texture mNEXT[3];
    sf::Sprite NEXT[3];
    sf::Vector2i source;
    sf::Texture mFruits[11];
    FRUITS Fruits[11];
    sf::Vector2i source1;
    sf::Clock clock1;
    sf::Sound sound;
    sf::SoundBuffer buffer;
    sf::Sound sound1;
    sf::SoundBuffer buffer1;
    sf::Sound sound2;
    sf::SoundBuffer buffer2;
    sf::Sound soundm;
    sf::SoundBuffer bufferm;
    sf::Texture mStart;
    sf::Sprite Start;
    bool mIsMovingLeft, mIsMovingRight;
    float PlayerSpeed,FruitSpeed;
    float frameCounter, switchFrame;
    int prut;
    void check();
    int collision(sf::Sprite);
    int lives;
    int score;
    std::vector<FRUITS> prutas;
    sf::Text point,sore,over,hort,spac;
    sf::Font font;
    void select(sf::Vector2i);
    bool menu,more1,duwa,overs,more2,more3;
};

int main(){
    Game game;
    game.run();
}

Game::Game():mWindow(sf::VideoMode(480, 640), "POKEFRUIT!"){
    lives=3;
    score=0;
    srand((unsigned int)time(NULL));
    menu=true;
    more1=duwa=overs=more2=more3=false;
    if (!mStart.loadFromFile("img/main.png")){
        cout<<"Error loading file."<<endl;
    }
    Start.setTexture(mStart);
    Start.setPosition(0.f, 0.f);
    if (!mNEXT[0].loadFromFile("img/more1.png")){
        cout<<"Error loading file."<<endl;
    }
    NEXT[0].setTexture(mNEXT[0]);
    NEXT[0].setPosition(0.f, 0.f);
    if (!mNEXT[1].loadFromFile("img/more2.png")){
        cout<<"Error loading file."<<endl;
    }
    NEXT[1].setTexture(mNEXT[1]);
    NEXT[1].setPosition(0.f, 0.f);
    if (!mNEXT[2].loadFromFile("img/more3.png")){
        cout<<"Error loading file."<<endl;
    }
    NEXT[2].setTexture(mNEXT[2]);
    NEXT[2].setPosition(0.f, 0.f);
    if (!buffer.loadFromFile("music/main.ogg")){
    cout<<"No Music"<<endl;
    }
    sound.setBuffer(buffer);
    if (!bufferm.loadFromFile("music/menu.ogg")){
    cout<<"No Music"<<endl;
    }
    soundm.setBuffer(bufferm);
    soundm.setPlayingOffset(sf::seconds(53));
    soundm.play();
    soundm.setLoop(true);
    if (!buffer1.loadFromFile("music/point.wav")){
        cout<<"No Music"<<endl;
    }
    sound1.setBuffer(buffer1);
    if (!buffer2.loadFromFile("music/error.wav")){
        cout<<"No Music"<<endl;
    }
    sound2.setBuffer(buffer2);
    if (!font.loadFromFile("font/Orange Juice.ttf")){
        cout<<"No Font"<<endl;
    }
    if (!mBG.loadFromFile("img/border.png")){
        cout<<"Error loading file."<<endl;
    }
    BG.setTexture(mBG);
    BG.setPosition(0.f, 0.f);
    if (!mlife[0].loadFromFile("img/life1.png")){
        cout<<"Error loading file."<<endl;
    }
    life[0].setTexture(mlife[0]);
    life[0].setPosition(330.f, 2.f);
    if (!mlife[1].loadFromFile("img/life2.png")){
        cout<<"Error loading file."<<endl;
    }
    life[1].setTexture(mlife[1]);
    life[1].setPosition(330.f, 2.f);
    if (!mlife[2].loadFromFile("img/life3.png")){
        cout<<"Error loading file."<<endl;
    }
    life[2].setTexture(mlife[2]);
    life[2].setPosition(330.f, 2.f);
    if (!mlife[3].loadFromFile("img/life4.png")){
        cout<<"Error loading file."<<endl;
    }
    life[3].setTexture(mlife[3]);
    life[3].setPosition(330.f, 2.f);
    if (!mFruits[0].loadFromFile("img/epol.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[0].setTexture(mFruits[0]);
    Fruits[0].s=1;
    if (!mFruits[1].loadFromFile("img/manda.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[1].setTexture(mFruits[1]);
    Fruits[1].s=1;
    if (!mFruits[2].loadFromFile("img/peach.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[2].setTexture(mFruits[2]);
    Fruits[2].s=1;
    if (!mFruits[3].loadFromFile("img/plum.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[3].setTexture(mFruits[3]);
    Fruits[3].s=1;
    if (!mFruits[4].loadFromFile("img/pear.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[4].setTexture(mFruits[4]);
    Fruits[4].s=10;
    if (!mFruits[5].loadFromFile("img/life.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[5].setTexture(mFruits[5]);
    Fruits[5].s=-1;
    if (!mFruits[6].loadFromFile("img/pine.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[6].setTexture(mFruits[6]);
    Fruits[6].s=10;
    if (!mFruits[7].loadFromFile("img/melon.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[7].setTexture(mFruits[7]);
    Fruits[7].s=80;
    if (!mFruits[8].loadFromFile("img/tire.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[8].setTexture(mFruits[8]);
    Fruits[8].s=0;
    if (!mFruits[9].loadFromFile("img/magnet.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[9].setTexture(mFruits[9]);
    Fruits[9].s=0;
    if (!mFruits[10].loadFromFile("img/trash.png")){
        cout<<"Error loading file."<<endl;
    }
    Fruits[10].setTexture(mFruits[10]);
    Fruits[10].s=0;
    if (!mPlayer.loadFromFile("img/basket.png")){
        cout<<"Error loading file."<<endl;
    }
    Player.setTexture(mPlayer);
    Player.setPosition(190.f, 590.f);
    mIsMovingLeft = mIsMovingRight = false;
    PlayerSpeed = 300.0;
    FruitSpeed =100.0;
    frameCounter = 0;
    switchFrame = 100;
    point.setFont(font);
    point.setColor(sf::Color::Yellow);
    point.setCharacterSize(30);
    point.setString("Score: ");
    point.setPosition(20,0);
    hort.setFont(font);
    hort.setColor(sf::Color::Red);
    hort.setCharacterSize(30);
    hort.setString("Lives: ");
    hort.setPosition(250,0);
    sore.setFont(font);
    sore.setColor(sf::Color::Yellow);
    sore.setCharacterSize(30);
    sore.setPosition(100,0);
    over.setFont(font);
    over.setColor(sf::Color::Yellow);
    over.setCharacterSize(50);
    over.setString("GAME OVER");
    over.setPosition(100,270);
    spac.setFont(font);
    spac.setColor(sf::Color::Yellow);
    spac.setCharacterSize(15);
    spac.setString("(Press SPACE to go back to Main Menu)");
    spac.setPosition(102,322);

}

void Game::run(){
    sf::Clock clock;
    while (mWindow.isOpen()){
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::select(sf::Vector2i pos){
    if(pos.x>=240&&pos.x<=480&&pos.y>=395&&pos.y<=475&&menu){
        duwa=true;
        menu=false;
        more1=false;
        soundm.pause();
        sound.play();
        sound.setLoop(true);
    }
    if(pos.x>=240&&pos.x<=480&&pos.y>475&&pos.y<=555&&menu){
        duwa=false;
        menu=false;
        more1=true;
    }
    if(pos.x>=400&&pos.x<=475&&pos.y>=608&&pos.y<=625&&more3){
        lives=9999999;
        score=9999999;
    }
    if(pos.x>=400&&pos.x<=475&&pos.y>=608&&pos.y<=625&&more2){
        duwa=false;
        menu=false;
        more1=false;
        more2=false;
        more3=true;
    }
    if(pos.x>=12&&pos.x<=88&&pos.y>=14&&pos.y<=34&&more1){
        duwa=false;
        menu=true;
        more1=false;
    }
    if(pos.x>=400&&pos.x<=475&&pos.y>=608&&pos.y<=625&&more1){
        duwa=false;
        menu=false;
        more1=false;
        more2=true;
    }
    if(pos.x>=12&&pos.x<=88&&pos.y>=14&&pos.y<=34&&more2){
        duwa=false;
        menu=false;
        more1=true;
        more2=false;
    }
    if(pos.x>=12&&pos.x<=88&&pos.y>=14&&pos.y<=34&&more3){
        duwa=false;
        menu=false;
        more1=false;
        more2=true;
        more3=false;
    }
}

void Game::processEvents(){
    sf::Event event;
    while (mWindow.pollEvent(event)){
        if(menu||more1||more2||more3){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            select(sf::Mouse::getPosition(mWindow));
            }
            else
            if (event.type == sf::Event::Closed)
                mWindow.close();
        }
        if(duwa||overs){
            switch(event.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
            }
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if(duwa){
        if(!isPressed){
        source.x = 0;
        source.y = 0;
        }
        if(key == sf::Keyboard::A){
            mIsMovingLeft = isPressed;
            if(isPressed){
                source.y = 0;
                source.x = 0;
            }
        }
        if(key == sf::Keyboard::D){
            mIsMovingRight = isPressed;
            if(isPressed){
                source.y = 0;
                source.x = 0;
            }
        }
        if(key == sf::Keyboard::Escape){
            if(isPressed){
                duwa=false;
                menu=true;
                more1=false;
                overs=false;
                soundm.setPlayingOffset(sf::seconds(53));
                soundm.play();
                soundm.setLoop(true);
                sound.stop();
                lives=3;
                score=0;
                FruitSpeed=100.0;
                prutas.clear();
            }
        }
        if(key == sf::Keyboard::F5){
            if(isPressed){
                lives=3;
                score=0;
                FruitSpeed=100.0;
                prutas.clear();
            }
        }
        source1.x = 0;
        source1.y = 0;
    }
    if(overs){
        if(key == sf::Keyboard::Space){
            if(isPressed){
                duwa=false;
                menu=true;
                more1=false;
                overs=false;
                soundm.setPlayingOffset(sf::seconds(53));
                soundm.play();
                soundm.setLoop(true);
                sound.stop();
                lives=3;
                score=0;
                FruitSpeed=100.0;
            }
        }
    }
}

void Game::update(sf::Time deltaTime){
    if(duwa){
        srand((unsigned int)time(NULL));
        sf::Time time = clock1.getElapsedTime();
        std::stringstream ss;
        ss << score;
        sore.setString( ss.str().c_str() );
        Player.setTextureRect(sf::IntRect(source.x*100,source.y*100,100,100));
        sf::Vector2f movement(0.f, 0.f);
        sf::Vector2f fall(0.f, 0.f);
        if(mIsMovingLeft){
            if(Player.getPosition().x>20)
                movement.x -= PlayerSpeed;
            else
                movement.x = 0;
        }

        if(mIsMovingRight){
            if(Player.getPosition().x<360)
                movement.x += PlayerSpeed;
            else
                movement.x = 0;
        }
        if(lives){
            if(time.asMilliseconds() >= 4000 && score<=100){
                prut=rand()%11;
                int xx=rand()%380+20;
                if(prut==7){
                    Fruits[7].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[7]);
                }
                else
                if(prut==3||prut==4){
                    if(rand()%3+1==1){
                        Fruits[5].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[5]);
                    }
                    else
                    if(rand()%3+1==2){
                        Fruits[6].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[6]);
                    }
                    else{
                        Fruits[4].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[4]);
                    }
                }
                else
                if(prut==2){
                    int yy=rand()%3+8;
                    Fruits[yy].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[yy]);
                }
                else{
                    int y=rand()%3;
                    Fruits[y].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[y]);
                }
                clock1.restart();
            }

            if(time.asMilliseconds() >= 2000&&score>100&&score<=250){
                prut=rand()%11;
                int xx=rand()%380+20;
                if(prut==7){
                    Fruits[7].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[7]);
                }
                else
                if(prut==3||prut==4){
                    if(rand()%3+1==1){
                        Fruits[5].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[5]);
                    }
                    else
                    if(rand()%3+1==2){
                        Fruits[6].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[6]);
                    }
                    else{
                        Fruits[4].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[4]);
                    }
                }
                else
                if(prut==2||prut==8){
                    int yy=rand()%3+8;
                    Fruits[yy].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[yy]);
                }
                else{
                    int y=rand()%3;
                    Fruits[y].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[y]);
                }
                clock1.restart();
            }

            if(time.asMilliseconds() >= 1000&&score>250&&score<=500){
                prut=rand()%11;
                int xx=rand()%380+20;
                FruitSpeed=200;
                if(prut==7){
                    Fruits[7].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[7]);
                }
                else
                if(prut==3||prut==4){
                    if(rand()%3+1==1){
                        Fruits[5].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[5]);
                    }
                    else
                    if(rand()%3+1==2){
                        Fruits[6].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[6]);
                    }
                    else{
                        Fruits[4].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[4]);
                    }
                }
                else
                if(prut==2||prut==8||prut==1){
                    int yy=rand()%3+8;
                    Fruits[yy].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[yy]);
                }
                else{
                    int y=rand()%3;
                    Fruits[y].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[y]);
                }
                clock1.restart();
            }

            if(time.asMilliseconds() >= 800&&score>500){
                prut=rand()%11;
                int xx=rand()%380+20;
                FruitSpeed=300;
                if(prut==7){
                    Fruits[7].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[7]);
                }
                else
                if(prut==3||prut==4){
                    if(rand()%3+1==1){
                        Fruits[5].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[5]);
                    }
                    else
                    if(rand()%3+1==2){
                        Fruits[6].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[6]);
                    }
                    else{
                        Fruits[4].setPosition(xx, 0.f);
                        prutas.push_back(Fruits[4]);
                    }
                }
                else
                if(prut==2||prut==8||prut==1||prut==6){
                    int yy=rand()%3+8;
                    Fruits[yy].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[yy]);
                }
                else{
                    int y=rand()%3;
                    Fruits[y].setPosition(xx, 0.f);
                    prutas.push_back(Fruits[y]);
                }
                clock1.restart();
            }
            check();
            fall.y+=FruitSpeed;

        }
        for(int i=0;i<prutas.size();i++)
        prutas[i].move(fall*deltaTime.asSeconds());
        Player.move(movement * deltaTime.asSeconds());

        if(lives==0){
            overs=true;
            prutas.clear();
        }
    }
}

void Game::check(){
    for (int i=0; i<prutas.size();i++){
        int type = collision(prutas[i]);
        if(type==1){
            if(prutas[i].s==0) {
                lives--;
                sound2.play();
            }
            else
            if(prutas[i].s==-1){
                if(lives<4) lives++;
                else score+=10;
                sound1.play();
            }
            else{
                score+=prutas[i].s;
                sound1.play();
            }
            prutas.erase(prutas.begin()+i);
        }
        if(type==3){
            if (score>0&&prutas[i].s!=-1) {
                if(score-prutas[i].s<0) score=0;
                else score-=prutas[i].s;
            }
            prutas.erase(prutas.begin()+i);
        }
    }
}

int Game::collision(sf::Sprite a){
    if(Player.getGlobalBounds().intersects(a.getGlobalBounds())) return 1;
    if(a.getPosition().y<590) return 2;
    return 3;
}

void Game::render(){
    mWindow.clear();
    if(menu) mWindow.draw(Start);
    if(duwa){
        mWindow.draw(BG);
        for(int i=0;i<prutas.size();i++)
        mWindow.draw(prutas[i]);
        if(lives!=0) mWindow.draw(Player);
        mWindow.draw(point);
        mWindow.draw(sore);
        mWindow.draw(hort);
        if(lives==1) mWindow.draw(life[0]);
        if(lives==2) mWindow.draw(life[1]);
        if(lives==3) mWindow.draw(life[2]);
        if(lives==4) mWindow.draw(life[3]);
        if(lives<=0) {
            mWindow.draw(over);
            mWindow.draw(spac);
        }
    }
    if(more1) mWindow.draw(NEXT[0]);
    if(more2) mWindow.draw(NEXT[1]);
    if(more3) mWindow.draw(NEXT[2]);
    mWindow.display();
}
