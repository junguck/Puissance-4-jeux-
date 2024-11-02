#include <iostream>
#include <stdlib.h>
#include <string>

void drawGrid(int grid[7][6]);
bool playTurn(int grid[7][6], int column, int player);
int score1=0;
int score2=0;
int x,y,reponse;
int win=0;
int main(int argc, char** argv){
    int grille[7][6] = {};
    std::string choix;

    int player = 1;
        drawGrid(grille);
        std::cout<<"[1]pour jouer a partie a 2;[2]pour jouer avec l IA"<<std::endl;
        std::cin>>reponse;
        switch(reponse){
            case 1:{
while (true){
        std::cout << "player_" << player << " -> col :";
        std::cin >> choix;

        if (choix == "exit"){
            break;
        }

        bool success = false;

        if (choix.size() == 1){
            if (choix[0] >= '0' && choix[0] <= '7'){
                int col = choix[0]  - '0';

                success = playTurn(grille, col, player);
            }
        }

        system("CLS");

        if (!success){
            std::cout << "votre choix est incorrect\n";
        } else{
            if (player == 1) player = 2;
            else player = 1;
        }
        for(x=0;x<7;x++){
            for(y=0;y<6;y++){
                if(grille[x][y]==1){
                    if(grille[x][y+1]==1){
                        if(grille[x][y+2]==1){
                            if(grille[x][y+3]==1){
                                
                                    win=1;
                                
                            }
                        }

                    }else if(grille[x+1][y]==1){
                        if(grille[x+2][y]==1){
                            if(grille[x+3][y]==1){
                                
                                    win=1;
                                
                            }
                        }

                    }else if(grille[x+1][y+1]==1){
                        if(grille[x+2][y+2]==1){
                            if(grille[x+3][y+3]==1){
                                
                                    win=1;
                                
                            }
                        }
                    }else if(grille[x][y-1]==1){
                        if(grille[x][y-2]==1){
                            if(grille[x][y-3]==1){
                                
                                    win=1;
                                
                            }
                        }
                    }else if(grille[x-1][y]==1){
                        if(grille[x-2][y]==1){
                            if(grille[x-3][y]==1){
                                
                                    win=1;
                                
                            }
                        }
                    }else if(grille[x-1][y-1]==1){
                        if(grille[x-2][y-2]==1){
                            if(grille[x-3][y-3]==1){
                                
                                    win=1;
                            }
                        }
                    }
                }
            }
        }
        //
        for(x=0;x<7;x++){
            for(y=0;y<6;y++){
                if(grille[x][y]==2){
                    if(grille[x][y+1]==2){
                        if(grille[x][y+2]==2){
                            if(grille[x][y+3]==2){
                                
                                    win=2;
                                
                            }
                        }

                    }else if(grille[x+1][y]==2){
                        if(grille[x+2][y]==2){
                            if(grille[x+3][y]==2){
                               
                                    win=2;
                                
                            }
                        }

                    }else if(grille[x+1][y+1]==2){
                        if(grille[x+2][y+2]==2){
                            if(grille[x+3][y+3]==2){
                                
                                    win=2;
                                
                            }
                        }
                    }else if(grille[x][y-1]==2){
                        if(grille[x][y-2]==2){
                            if(grille[x][y-3]==2){
                                
                                    win=2;
                                
                            }
                        }
                    }else if(grille[x-1][y]==2){
                        if(grille[x-2][y]==2){
                            if(grille[x-3][y]==2){
                               
                                    win=2;
                                
                            }
                        }
                    }else if(grille[x-1][y-1]==2){
                        if(grille[x-2][y-2]==2){
                            if(grille[x-3][y-3]==2){
                                    win=2;
                                
                            }
                        }
                    }
                }
            }
        }
        drawGrid(grille);
        if(win!=0){
            break;
        }
    }
            }

            //ia
            case 2:{
                break;
            }
       
        }
    
    std::cout<<"le gagnant est le joueur"<<win<<std::endl;
    return 0;
}


// 0, 1, 2
void drawGrid(int grille[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grille[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grille[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool playTurn(int grid[7][6], int column, int player){
    for (int line = 5 ; line >= 0; line--){
        if (grid[column - 1][line] == 0){
            grid[column - 1][line] = player;
            return true;
        }
    }
    return false;
}