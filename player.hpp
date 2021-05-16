class Player
{
private:
int Points;

Player():Points(0) {};

void addPoints(int P=1)
{
Points++;
}

int operator++()
{
addPoints();
};

};