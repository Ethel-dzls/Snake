//Structure position 
struct Position {
    int x;
    int y;

    //Pour comparer les positions entre elles
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};


//Structure du plateau (pas fait)
struct Plateau {
    int width;
    int height;

    //x augmente vers la droite, y augmente vers le bas
    bool est_un_mur(Position pos) const {
        return pos.x == 0 || pos.x == width - 1 ||
               pos.y == 0 || pos.y == height - 1 ||
               pos.x < 0 || pos.x >= width ||
               pos.y < 0 || pos.y >= height;
    }
};


//Structure serpent : 

//Enumération des directions
enum class Direction {
    Up,
    Down,
    Left,
    Right,
};

//Structure du serpent
struct Snake {
    std::vector<Position> body{};

    //On initialise ces variables
    Direction direction {Direction::Up};
    int score{0};
};

//Serpent initial
Snake init_snake(){
    std::vector<Position> body_init{ {5, 5}, {5, 6} };
    Direction dir_init {Direction::Up};
    Snake snake_init {body_init, dir_init, 0};

    return snake_init;
}

//Calcul nouvelle position de la tête
Position nv_pos_tete(Position pos_tete, Direction dir){
    if (dir == Direction::Up){
        pos_tete.y -=1;
    }

    else if (dir == Direction::Down){
        pos_tete.y +=1;
    }

    else if (dir == Direction::Left){
        pos_tete.x -=1;
    }

    else if (dir == Direction::Right){
        pos_tete.x +=1;
    }

    return pos_tete;
}

//Déplacer le reste du corps du serpent
std::vector<Position> deplacement_corps(std::vector<Position> pos_snake, Position ancienne_pos_tete){

    if (size < 2){
        return pos_snake;
    }

    //Chaque partie du corps prend la position de la précédente
    for (int i{pos_snake.size() - 1}; i >= 2 ; i--){
        pos_snake[i]=pos_snake[i - 1];
    }
    pos_snake[1]=ancienne_pos_tete;

    return pos_snake;
}


//Vérifier si le serpent se heurte à lui-même
bool verif_auto_collision(Snake snake) {

    Position tete = snake.body[0];

    for (int i{1}; i < snake.body.size(); i++) {

        if (tete == snake.body[i]) {
            return true;
        }
    }

    return false;
}


//Changer la direction du serpent
void changer_dir(Snake& snake, Direction nv_dir) {
    snake.direction = nv_dir;
}


