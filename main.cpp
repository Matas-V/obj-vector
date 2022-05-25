#include "headers/main.h"
#include <vector>
#include "funkcijos.cpp"

int main() {
  int n=0, kiek;
  string med, gen, k, genf;
  bool pass=0;
  Vector<studentas> mas;
  Vector<int> b;
  vector<int> a;
  b.push_back(20); b.push_back(40); b.push_back(50); b.push_back(99);
  a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
  studentas S;
  mas.reserve(2);
  srand(time(0));

  cout << a.max_size() << endl;
  cout << b.max_size() << endl;
  cout << a.size() << endl;
  cout << b.size() << endl;

  input_check(gen, "Ar duomenis ivedinesite(1) pats ar sugeneruoti(0)?");

  if (gen == "0") {
    n = rand() % 10 + 1;
    med = rand() % 10 >= 5 ? "1" : "0";
    pass = 1;
  } else {
    input_check(genf, "Ar reikalingas failu generavimas? Taip(1) ar ne(0)");
    input_check(gen, "Ar duomenis ivedinesite ranka(1) ar skaityti is failo(0)?");

    if (genf == "1") {
      cout << "Kiek pazymiu tures kiekvienas studentas? "; cin >> kiek;
      for (int i=0; i<5; i++)
        failuGeneravimas(fileNames[i], stoi(regex_replace(fileNames[i], regex("[^0-9]*([0-9]+).*"), string("$1"))), kiek);
    }
    input_check(med, "Pasirinkite ka noresit skaiciuoti galutinio ivertinimo: vidurki(0) ar mediana(1)?");

    if (gen == "0") {
      for (int i=0; i<5; i++) {
        auto start = high_resolution_clock::now();
        S.readStudentai(mas, fileNames[i], med, i);
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout <<"Darbo su failu testo laikas: " << diff.count() << endl;
        mas.clear();
        cout << endl;
        system("pause");
      }
    } else {
      while(!pass) {
        cout << "Kiek studentu noresite ivesti?" << endl;
        cin >> k;
        if (int(k[0]) >= 49 && int(k[0]) <= 57) {
          if (stoi(k) <= arr_size && stoi(k) > 0) {
            n = stoi(k);
            pass=1;
          }
        }
      }
    }
  }

  // unsigned int sz = 100000000;
  // vector<int> v1;
  // int v1_add = 0, szs = 0;
  // auto start = std::chrono::high_resolution_clock::now();
  // for (int i = 1; i <= sz; ++i) {
  //   if (v1.capacity() != szs) {
  //     szs = v1.capacity();
  //     v1_add++;
  //   }
  //   v1.push_back(i);
  // }
  // auto end = std::chrono::high_resolution_clock::now();
  // std::chrono::duration<double> diff = end - start;
  // cout << "vector laikas: " << diff.count() << endl;
  // cout << "vector perskirstymas: " << v1_add << endl;

  // Vector<int> v2;
  // start = std::chrono::high_resolution_clock::now();
  // for (int i = 1; i <= sz; ++i) {
  //   if (v2.capacity() != szs) {
  //     szs = v2.capacity();
  //     v1_add++;
  //   }
  //   v2.push_back(i);
  // }
  // end = std::chrono::high_resolution_clock::now();
  // diff = end - start;
  // cout << "Mano vector laikas: " << diff.count() << endl;
  // cout << "Mano vector perskirstymas: " << v1_add << endl;

  if (pass) {
    for (int i=0; i<n; i++) {
      mas.reserve(mas.size() + 1);
      if (gen == "0") {
        mas.push_back(generavimas());
      } else {
        mas.push_back(ivestis());
      }
    }
    isvedimas(mas, mas.size(), med);
    system("pause");
  }

  return 0;
}