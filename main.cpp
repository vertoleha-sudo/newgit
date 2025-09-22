#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
  srand(time(0));
  int numbers[30];

  for (int i = 0; i < 30; i++) {
    numbers[i] = rand() % 10 + 1;
  }
  
  for (int i = 0; i < 3; i++) {
    int increasing_sequences = 0;
    int decreasing_sequences = 0;
    string filename = "file" + to_string(i + 1) + ".txt";
    cout << "Создаю " << filename << "... " << endl;
    ofstream file(filename);
    cout << "Заполняю данными..." << endl;

    int start = i * 10;
    int end = start + 9;

    for (int j = start; j <= end; j++) {
      file << numbers[j] << " ";
      
      if (j > start) {
        if (numbers[j] > numbers[j - 1]) {
          increasing_sequences++;
        }
        else if (numbers[j] < numbers[j - 1]) {
          decreasing_sequences++;
        }
      }
    }

    file.close();
    cout << "Готово!" << endl;
    
    // Вывод статистики по последовательностям
    cout << "Возрастающих последовательностей: " << increasing_sequences << ", убывающих: " << decreasing_sequences << endl;
  }
  return 0;
}
