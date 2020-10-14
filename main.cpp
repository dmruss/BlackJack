#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

class Player {
	private:
		vector<int> cards;
		int sum;
	public:
		Player() {
			srand(time(NULL));
			cards.push_back(rand()%10+1);
			cards.push_back(rand() % 10 + 1);
		}

		void sumCards() {
			sum = 0;
			for (int i = 0; i < cards.size(); i++) {
				sum += cards[i];
			}
		}
		void hitMe() {
			cards.push_back(rand() % 10 + 1);
		}
		void printCards() {
			for (int i = 0; i < cards.size(); i++) {
				cout <<"Card " << i << ": " << cards[i] << endl;
			}
		}
		void printSum() {
			cout << "Total: " << sum << endl;
		}
		int getSum() {return sum;}
};

int main() {

	//start game
	Player *aPlayer = new Player();
	Player *dealer = new Player();
	bool gameOver = false;
	char answer;

	while (!gameOver) {
		aPlayer->printCards();
		aPlayer->sumCards();
		aPlayer->printSum();
		dealer->sumCards();
		if (aPlayer->getSum() > 21) {
			cout << "Bust!" << endl;
			gameOver = true;
		}
		if (dealer->getSum() > 21) {
			cout << "Dealer busts! You win!" << endl;
			gameOver = true;
		}
		if (!gameOver) {
			cout << "Hit, stay, or quit? (h, s, or q)" << endl;
			try {
				cin >> answer;
			}
			catch (char answer) {
				cout << "Invalid input" << endl;
			}
			switch (answer) {
				case 'h':
					aPlayer->hitMe();
					dealer->hitMe();
					break;
				case 's':
					cout << "You choose to stay" << endl;
				case 'q':
					cout << "Goodbye" << endl;
					gameOver = true;
					break;
				default:
					cout << "What was that?" << endl;
			}
		}
	}

	return 0;
}
