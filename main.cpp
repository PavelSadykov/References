//
//  main.cpp
//  References - указатели продолжение и ссылки
//
//  Created by Павел on 16.09.2022.
//

#include <iostream>
using namespace std;

template <typename T>
void show_arr(T *arr, const int length){
    cout<<"[";
    for (int i=0; i<length;i++)
        cout << arr[i]<<" ";
    cout<<"]\n";
}



int mx[10][2];




void my_swap(int num1, int num2){ // не работает
    int tmp=num1;
    num1=num2;
    num2=tmp;
}

void pswap(int *pnum1, int *pnum2){// работает
    int tmp=*pnum1;
    *pnum1=*pnum2;
    *pnum2=tmp;
}
template <typename T>
void refswap(T &refnum1,T &refnum2){// работает
    T tmp = refnum1;
    refnum1 =refnum2;
    refnum2=tmp;
}

int &func(int index){
    return mx[index][1];
}

template <typename T>
T &ref_max(T arr[], const int length){
    T tmp = 0;
    for(int i=1;i<length;i++)
        if(arr[i]> arr[tmp])
            tmp = i;
    return arr[tmp]; //функция возвращает ссылку на максимальный элемент масс.
}

// Задача1.
template <typename T>
void two_var (T &num1, T &num2){
if(num1 > num2){
    num1*=num1;//num1 = pow(num1,2)  при этом надо подключить cmath
    num2*=num2;
} else
    num1=0;
    num2=0;
}


//Задача 2. Копирование массивов
template <typename T1,typename T2>
void copy_arr(
    T1 arr1[],const int length1, T2 arr2[],const int length2){
    int min_len = length1 < length2 ? length1 : length2;
    for(int i = 0; i < min_len; i++)
        *(arr2 + i) = *(arr1 + i);
    
}



int main(int argc, const char * argv[]) {
    int n = 10, m = 15;
    
    
    /*
    //Максимальный элемент массива
    int arr_max[5]{4,7,2,-9,6};
    cout<<"Изначальный массив : \n";
    show_arr(arr_max,5);
    cout<<"Максимум  : "<<ref_max(arr_max,5)<<endl;
    ref_max(arr_max, 5)=0; //функция меняет макс элемент на 0
    ref_max(arr_max, 5)=0;// еще один элемент меняется на 0
    ref_max(arr_max, 5)=0;// еще один...
    cout<<"Итоговый массив : \n";
    show_arr(arr_max,5);
    cout<<endl;
    */
    
    /*
    //Вводим 10 чисел, получаем двумерный массив из этих же чисел
    for(int i=0;i<10;i++){
        cout<<"ВВедите число : ";
        cin>>mx[i][0];
        func(i) = mx[i][0];
    }
    cout<<"Итоговый массив : \n";
    for(int i=0;i<10;i++){
        cout<<mx[i][0]<<"  "<<func(i)<<endl;
    }
     
     */
   /*
    //Использование  ссылок для замены переменных местами
    my_swap(n,m);//не работает
    cout<<n<<"  "<<m<<endl;
    
        n=10;m=15;
    pswap(&n,&m);//работает но неудобно
    cout<<n<<"  "<<m<<endl;
    
        n=10;m=15;
    refswap(n, m);//отлично работает
    cout<<n<<"  "<<m<<endl;
    
    */
    
    //Указатель.
   // int *pn = &n;
   // cout<<*pn<<endl;//Для обращения к переменной требуется разименование
    // Ссылка. Ссылка - это тот же указатель , но не требующий разименования
    //Ссылка - альтернативное название переменной, обладающее доступом к ней из любого блока када
   // int &refm = m;
   // refm = 20;
   // cout<<"Новая m = "<<m<<endl;
    
    
    /*
    //Указатель на константу // нельзя менять значение объекта используя разименование указателя

    int const *pn;
    pn = &n;
   // *pn = 5; //ошибка. так как нельзя менять значение переменной
    */
     
    //Константный указатель //нельзя перенаправить на другую область памяти, но можно менять переменную используя разименование
   /* const int *pn = &n;
    pn = &m;// ошибка но не точно
   */
    
    // Константный указатель на константу//нельзя менять значение объекта через разименование и нельзя перенапралять на другую область памяти
   // const int const *pn = &n;
   // *pn =5; //ошибка
    //pn = &m; //ошибка
    
   // ПРИМЕР
   // int mass[5]{}; // все элементы  = 0
   // mass = &n; // ошибка так как название массива является константным указателем
    
    
   /*
    // Нейтральные указатели
    int *pn;
    //ошибка при обращении к неинициализированному указателю
    //cout <<pn<<endl;
    
   
    pn=0; // Первый способ инициализации указателя
    if(pn)//если pn не равен 0/ проверяем является ли адрес нейтральным то есть = 0?
    cout <<*pn<<endl;
    else
        cout<<"Указатель не инициализирован \n";
    */
    /*
    // Второй способ
    //pn = NULL;// абсолютно то же самое
    
    //Третий способ
    pn = nullptr;//nullptr - это не число. Проверка на нейтральность указателя
    // если он нейтрален. то есть равен 0, то его нельзя использовать
    if(pn==nullptr)
        cout<<"Указатель не инициализирован \n";
    else
        cout<<pn<<endl;
    */
    
    /*
    
    //Задача1. создать функцию которая принимает 2 переменные . Если 1  больше, то они обе возводятся в квадрат. Иначе они обнуляются.
    cout<<"Введите 2 числа : ";
    cin>>n>>m;
    two_var(n,m);
    cout<<"n = "<<n<<endl;
    cout<<"m = "<<m<<endl;
    */
    
    //Задача 2. Используя 2 указателя на массивы целых чисел, скопировать один массив  в другой. Использовать арифметику указателей для продвижения по массиву, а также оператор разыменования
    
    const int size1 =5;
    const int size2 =7;
    int arr1[size1]{4,2,1,6,7};
    int arr2[size2]{};
    cout<<" 1  массив  : " ;
    show_arr(arr1,size1);
    copy_arr(arr1,size1,arr2,size2);
    cout<<" 2  массив  : " ;
    show_arr(arr2,size2);
    
    return 0;
}
