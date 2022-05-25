# obj-vector

## Spartos analizė su push_back()

| Int  | 10.000.000  | 100.000.000  | 1.000.000.000  |
|---|---|---|---|
| std::vector  | 0.026058 | 0.324054 | 3.04426 |
|  Mano vector | 0.025007 | 0.220046 | 2.49156 |

## Perskirstymai uzpildants 1.000.000.000 elementu
- std vector – 31
- Mano vector - 31

## Vektorių funkcijų palyginimas
### size()
```
Vector<int> b;
b.push_back(20); b.push_back(40); b.push_back(50); b.push_back(99);
cout << b.size() << endl;
```
OUTPUT: 4
```
std::vector<int> a;
a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
cout << a.size() << endl;
```
OUTPUT: 4

### max_size()
```
Vector<int> b;
cout << b.max_size() << endl;
```
OUTPUT: 76861433640456465

```
std::vector<int> a;
cout << a.max_size() << endl;
```
OUTPUT: 76861433640456465

### shrink_to_fit()
```
Vector<int> b;
b.push_back(20); b.push_back(40); b.push_back(50); b.push_back(99);
cout << b.size() << " ";
cout << b.capacity() << " ";
b.pop_back();
b.pop_back();
cout << b.size() << " ";
cout << b.capacity() << " ";
b.shrink_to_fit();
cout << b.size() << " ";
cout << b.capacity() << " ";
```
OUTPUT: 4 4 2 4 2 2

### at()
```
Vector<int> b;
b.push_back(20); b.push_back(40); b.push_back(50); b.push_back(99);
cout << b.at(1) << endl;
cout << b.at(10) << endl;
```
OUTPUT: 40
Ivyko klaida su at - out of range

### pop_back()
```
Vector<int> b;
b.push_back(20); b.push_back(40); b.push_back(50); b.push_back(99);
cout << b.back() << endl;
cout << b.size() << endl;
b.pop_back();
cout << b.back() << endl;
cout << b.size() << endl;
```
OUTPUT: 99 4 50 3

## Programos v1.5 veikimas naudojant std::vector ir mano vector

| studentu sk. | 1000 | 10.000 | 100.000 | 1.000.000 | 10.000.000 |
|---|---|---|---|---|---|
| std::vector | 0.010098 | 0.068031 | 0.606163 | 5.55985 | 41.8835 |
| Mano vector | 0.011002 | 0.093535 | 1.0307 | 13.3134 | 101.203 |
