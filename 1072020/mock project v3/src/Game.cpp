#include "Game.h"

Game::Game() {
    std::cout << "WELCOME TO FARM FUNNY\n";
}

void Game::handleUserInput( std::string input ) {
    std::istringstream iss( input );
    std::vector<std::string> words;
    do {
        std::string temp;
        iss >> temp;
        words.push_back(temp);
    }
    while ( iss );
    if ( words[0] == "exit" ) {
        return;
    }
    else if ( words[0] == "report" ) {
        player.report( words[1] );
    }
    else if ( words[0] == "feed" ) {
        player.feed( words[1] );
    }
    else if ( words[0] == "let" && words[2] == "out" ) {
        player.letOut( words[1] );
    }
    else if ( words[0] == "let" && words[2] == "back" ) {
        player.letBack( words[1] );
    }
    else if ( words[0] == "buy" ) {
        player.buy( words[1], words[2] );
    }
    else if ( words[0] == "sell" ) {
        if ( words.size() == 2 ) {
            player.sell( words[1] );
        }
        else {
            player.sell( words[1], words[2] );
        }
    }
}

void Game::update() {
    
}

void Game::run() {
    std::string command = "";
    do {
        std::cout << "Enter command: ";
        std::getline( std::cin, command );
        handleUserInput( command );
        update();
    }
    while ( command != "exit" );
}