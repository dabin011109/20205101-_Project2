// p590, 3번 문제

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

class Sprite {
protected:
	int x, y;
	char shape;
public:
	Sprite(int x, int y, char shape) : x(x), y(y), shape{ shape } { }
	virtual ~Sprite() { }

	virtual void move(char d) = 0;
	char getShape() { return shape; }

	int getX() { return x; }
	int getY() { return y; }

	bool checkCollision(Sprite* other) {
		if (x == other->getX() && y == other->getY())
			return true;
		else
			return true;
	}
};

class Hero :public Sprite {
public:
	Hero(int x, int y) :Sprite(x, y, 'H') { }
	void draw() { cout << 'H'; }
	void move(char d) {
		if (d == 'a') { x -= 1; }
		else if (d == 'w') { y -= 1; }
		else if (d == 's') { y += 1; }
		else if (d == 'd') { x += 1; }
	}
};

class Treasure :public Sprite {
public:
	Treasure(int x, int y) : Sprite(x, y, 'T') { }
	void move(char d) { }
};

class Enemy :public Sprite {
public:
	Enemy(int x, int y) : Sprite(x, y, 'E') { }
	void move(char d) {	}
};

class Board
{
	char* board;
	int width, height;
public:
	Board(int w, int h) : width{ w }, height{ h } {
		board = new char[width * height];
		clearBoard();
	}
	~Board() {
		delete board;
	}
	void setValue(int r, int c, char shape) {
		board[r * width + c] = shape;
	}
	void printBoard() {
		for (int i = 0; i < height; i++) {
			cout << "\t";
			for (int j = 0; j < width; j++)
				cout << board[i * width + j];
			cout << endl;
		}
	}
	void clearBoard() {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				board[i * width + j] = '.';
	}
};

void drawLine(char x)
{
	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << x;
	cout << endl;
}

int main()
{
	vector<Sprite*>list;
	int width, height;

	cout << "보드의 크기를 입력하시오[최대 10x10]: " << endl;
	cout << "가로: ";
	cin >> width;

	cout << "세로: ";
	cin >> height;

	Board board(height, width);
	list.push_back(new Hero(0, 0));
	list.push_back(new Treasure(height - 1, width - 1));
	list.push_back(new Enemy(3, 3));

	drawLine('*');
	cout << "이 게임의 목표는 함정(T)이나 적(E)을 만나지 않고 보물에 도달하는 것이다. ";
	cout << "주인공은 a, s, w, d 키를 이용하여 움직일 수 있다." << endl;
	drawLine('*');
	cout << endl;

	while (true)
	{
		board.clearBoard();
		for (auto& e : list)
			board.setValue(e->getY(), e->getX(), e->getShape());
		board.printBoard();

		char direction;
		try {
			cout << "어디로 움직일까요(a, s, w, d): ";
			cin >> direction;
			if (direction == 'a' && direction == 's' || direction == 'w' || direction == 'd') {
				for (auto& e : list)
					e->move(direction);
				drawLine('-');
			}
			else
				throw direction;
		}
		catch (char e) {
			cout << "오류 : " << e << "는 존재하지 않습니다." << endl;
		}
	}

	for (auto& e : list)
		delete e;
	list.clear();
}