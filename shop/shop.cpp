#include <iostream> 
//#include <Windows.h> 
#include <cstdlib> 
#include <iomanip> 
#include <string> 
#include <limits> 





//тематика - продажа шпаргалок на ОГЭ/ЕГЭ, название - Соточка

int size = 10;
int receiptSize = 1;


//массивы склада 
int* test = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

//массивы чека 
std::string* nameReceipt = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];





//функция 
void Start();
void CreateStorage();
template<typename ArrType>
void FillArray(ArrType staticArray[], ArrType dinArray[], int size);
template<typename ArrType>
void PrintArray(ArrType arr[], int size);
void Shop();
void ShowStorage();
void Selling();
void AddElementToReceipt(int& receiptSize, int id, int count);
void PrintReceipt();
void ChangePrice();
void RemoveFromStorage();
void AddToStorage();
void ChangeStorage();
void AddElementToEnd();
void DeletElementByIndex();


int main() {


    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    Start();
    

    delete[] test;
    delete[] nameArr;
    delete[] countArr;
    delete[] nameReceipt;
    delete[] countReceiptArr;
    delete[] priceReceiptArr;



    system("pause");
    return 0;
}

void Start()
{
    bool exit = false;
    std::string adminLogin = "lina";
    std::string adminPassword = "11235";
    std::string login, password;
    int choose;
    int chooseStorageType;


    std::cout << "\n\t\t\tДобро пожаловать в магазин *Соточка*" << std::endl;

    do
    {
        std::cout << "\n\tЛогин:   ";
        std::getline(std::cin, login, '\n');

        std::cout << "\tПароль:   ";
        std::getline(std::cin, password, '\n');

        if (login != adminLogin || password != adminPassword) {
            std::cerr << "\n\tНеверный логин и пароль\n\n";
            std::cout << "\n\tПопробовать ещё раз? 1 - да, 2 - выход из прогаммы\n\n";
            std::cin >> choose;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choose == 2)
            {
                exit = true;
            }
        }
        else {
            exit = true;
            int chooseStorageType;

            do
            {
                std::cout << "Выберите формат склада: \n1-Гoтовый склад\n2-Создать склад вручную \n";
                std::cin >> chooseStorageType;
            } while (chooseStorageType < 1 || chooseStorageType>2);
            if (chooseStorageType == 1)
            {
                CreateStorage();
                Shop();
            }
            else if (chooseStorageType == 2)
            {
                std::cout << "  ";

            }
            else
            {
                std::cout << "Error";

            }
        }
    } while (!exit);


}

void CreateStorage()
{
    const int staticSize = 10;
    int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9, };
    std::string name[staticSize]{ "ОГЭ математика", "ЕГЭ профиль","ОГЭ русский","ЕГЭ русский","ОГЭ биология", "ЕГЭ биология",
        "ЕГЭ информатика","ОГЭ физика", "ЕГЭ физика", "ЕГЭ химия" };
    int count[staticSize]{ 500, 510, 520, 530, 540, 550, 560, 570, 580, 590 };
    double price[staticSize]{ 425,559,499,499,445,469,509,399,444,479 };

    FillArray(id, test, staticSize);
    FillArray(name, nameArr, staticSize);
    FillArray(count, countArr, staticSize);
    FillArray(price, priceArr, staticSize);

}

void Shop()
{
    int choose;
    while (true)
    {

        do
        {
            std::cout << "1) Показать склад\n";
            std::cout << "2) Начать продажу\n";
            std::cout << "3) Изменить цену\n";
            std::cout << "4) Списать товар\n";
            std::cout << "5) Пополнить товар\n";
            std::cout << "6) Изменить склад\n";
            std::cout << "0) Закончить смену\n";
            std::cin >> choose;
        } while (choose < 0 || choose>6);
        if (choose == 1) 
        {
            ShowStorage();
        }
        else if (choose == 2) 
        {
            Selling();
        }
        else if (choose == 3) 
        {
            ChangePrice();
        }
        else if (choose == 4) 
        {
            RemoveFromStorage();
        }
        else if (choose == 5) 
        {
            AddToStorage();
        }
        else if (choose == 6)
        {
            ChangeStorage();
        }
        else if (choose == 0) 
        {



        }
        else
        {
            std::cout << "Error";
        }



    }
}

void ShowStorage()
{

    std::cout << "\tid товара\tНазвание\t\t\tЦена\t\tКол-во\n\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "\t" << test[i] + 1 << "\t\t" << nameArr[i] << "\t\t\t" << priceArr[i] << "\t\t" <<
            countArr[i] << "\n";
    }

}

void Selling()
{
    int chooseId, chooseCount, confirm;
    bool isFirst = true;
    while (true)
    {
        do
        {
            std::cout << "\nВведите id товара: ";
            std::cin >> chooseId;
            if (chooseId<1 || chooseId>size)
            {
                std::cerr << "Нет такого Id\n";
                continue;
            }
            if (countArr[chooseId - 1] > 0)
            {
                while (true)
                {
                    std::cout << "\nВы выбрали: " << nameArr[chooseId - 1] << "\n";
                    std::cout << "\nКол-во товара на складе:  " << countArr[chooseId - 1] << "\n";
                    std::cout << "Выберите кол-во товара для покупки: ";
                    std::cin >> chooseCount;
                    if (chooseCount<1 || chooseCount>countArr[chooseId - 1])
                    {
                        std::cerr << "Тoвара не хватает\n";
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            else
            {
                std::cerr << "Этого товара нет на складе\n";
                continue;
            }
            std::cout << "\nВы выбрали: " << nameArr[chooseId - 1] << "\n";
            std::cout << "В количестве:  " << chooseCount << "\n";
            std::cout << "Подтвердите выбор: \n1 - Всё хорошо\n2 - Повторить\n";
            std::cin >> confirm;

            if (confirm == 1)
            {
                if (isFirst)
                {
                    isFirst = false;
                    nameReceipt[receiptSize - 1] = nameArr[chooseId - 1];
                    countReceiptArr[receiptSize - 1] = chooseCount;
                    priceReceiptArr[receiptSize - 1] = priceArr[chooseId - 1] * chooseCount;
                    countArr[chooseId - 1] -= chooseCount;
                }
                else if (!isFirst)
                {
                    AddElementToReceipt(receiptSize, chooseId, chooseCount);

                }
            }
            /*PrintArray(nameReceipt, receiptSize);
            PrintArray(countReceiptArr, receiptSize);
            PrintArray(priceReceiptArr, receiptSize);*/
            else
            {
                continue;
            }
            std::cout << "Купить ещё один товар?\n1-Да\n2-Нет\n";
            std::cin >> confirm;
            if (confirm == 2)
            {
                break;
            }


        } while (true);

        PrintReceipt();
        //скидки и итог+скидки 


    }

}

template<typename ArrType>
void PrintArray(ArrType arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


void AddElementToReceipt(int& receiptSize, int id, int count)
{

    std::string* nameReceiptTemp = new std::string[receiptSize];
    int* countReceiptArrTemp = new int[receiptSize];
    double* priceReceiptArrTemp = new double[receiptSize];

    for (int i = 0; i < receiptSize; i++)
    {
        nameReceiptTemp[i] = nameReceipt[i];
        countReceiptArrTemp[i] = countReceiptArr[i];
        priceReceiptArrTemp[i] = priceReceiptArr[i];
    }
    delete[] nameReceipt;
    delete[] countReceiptArr;
    delete[] priceReceiptArr;

    receiptSize++;

    nameReceipt = new std::string[receiptSize];
    countReceiptArr = new int[receiptSize];
    priceReceiptArr = new double[receiptSize];

    for (int i = 0; i < receiptSize - 1; i++)
    {
        nameReceipt[i] = nameReceiptTemp[i];
        countReceiptArr[i] = countReceiptArrTemp[i];
        priceReceiptArr[i] = priceReceiptArrTemp[i];
    }

    nameReceipt[receiptSize - 1] = nameArr[id - 1];
    countReceiptArr[receiptSize - 1] = count;
    priceReceiptArr[receiptSize - 1] = priceArr[id - 1] * count;
    countArr[id - 1] -= count;


    delete[] nameReceiptTemp;
    delete[] countReceiptArrTemp;
    delete[] priceReceiptArrTemp;
    
}

void PrintReceipt()
{
    std::cout << "\tНазвание\t\t\tКол-во\t\tЦена\n\n";
    for (int i = 0; i < receiptSize; i++)
    {
        std::cout << "\t" << nameArr[i] << "\t\t\t" << countArr[i] << "\t\t" << priceArr[i] << "\n";
    }
}

void ChangePrice()
{

    int id;
    double newPrice;
    do
    {
        std::cout << "Введите id товара: ";
        std::cin >> id;

    } while (id<1 || id>test[size - 1]);
    std::cout << "\n\nТекущая цена продукта: " << nameArr[id - 1] << " = " << priceArr[id - 1];
    do
    {
        std::cout << "Введите новую цену: ";
        std::cin >> newPrice;

    } while (newPrice < 0.01 || newPrice>100000.03);
    priceArr[id - 1] = newPrice;
    std::cout << "Цена изменена";
}

template<typename ArrType>
void FillArray(ArrType staticArray[], ArrType dinArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dinArray[i] = staticArray[i];
       
    }
}
void RemoveFromStorage()
{
    int id; 
    int goodCout = 0;
    do
    {
        std::cout << "Введите id товара: ";
        std::cin >> id;
    } while (id<1 || id>test[size - 1]);
    std::cout << "\n\nТекущее количество товара: " << nameArr[id - 1] << " = " << countArr[id - 1];
    do
    {
        std::cout << "\nСколько списать товара со склада: ";
        std::cin >> goodCout;
    } while (goodCout < countArr[id - 1] || goodCout>10000.03);
    countArr[id - 1] = goodCout;
    std::cout << "Списание прошло успешно";
}

void AddToStorage()
{
    int id;
    int goodCount = 0;

    do
    {
        std::cout << "Введите id товара: ";
        std::cin >> id;
    } while (id < 1 || test[size - 1]);

    std::cout << "\n\nТекущее количество товара: " << nameArr[id - 1] << " = " << countArr[id - 1];
    do
    {
        std::cout << "\nСколько добавить товара со склада: ";
        std::cin >> goodCount;
    } while (goodCount < 0);
    countArr[id - 1] += goodCount;
    std::cout << "Добавление прошло успешно";
}

void ChangeStorage()
{
    int choose;
    do
    {
        std::cout << "Изменение склада.\n1 - добавить новый товар\n2 - удалить товар\n3 - выйти";
        std::cin >> choose;
    } while (choose < 1 || choose>3);

    if (choose == 1)
    {
        AddElementToEnd();
    }
    else if (choose == 2)
    {
        DeletElementByIndex();
    }
    else if (choose == 3)
    {
        std::cout << "Выход";
    }

}

void AddElementToEnd()
{
    int* idArrTemp = new int[size];
    std::string* nameArrTemp = new std::string[size];
    int* countArrTemp = new int[size];
    double* priceArrTemp = new double[size];

    for (int i = 0; i < size; i++)
    {
        idArrTemp[i] = test[i];
        nameArrTemp[i] = nameArr[i];
        countArrTemp[i] = countArr[i];
        priceArrTemp[i] = priceArr[i];
    }
    delete[] test;
    delete[] nameArr;
    delete[] countArr;
    delete[]priceArr;

    size++;
    test = new int[size];
    nameArr = new std::string[size];
    countArr = new int[size];
    priceArr = new double[size];

    for (int i = 0; i < size - 1; i++)
    {
        test[i] = idArrTemp[i];
        nameArr[i] = nameArrTemp[i];
        countArr[i] = countArrTemp[i];
        priceArr[i] = priceArrTemp[i];
    }

    test[size - 1] = size - 1;
    std::cout << "\nВведите имя нового товара";
    std::getline(std::cin, nameArr[size - 1]);
    std::cout << "\nВведите количество нового товара: ";
    std::cin >> countArr[size - 1];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nВведите цену нового товара: ";
    std::cin >> priceArr[size - 1];
    std::cout << "Товар успешно добавлен";


    delete[] idArrTemp;
    delete[] nameArrTemp;
    delete[] countArrTemp;
    delete[]priceArrTemp;
}

void DeletElementByIndex()
{
    int* idArrTemp = new int[size];
    std::string* nameArrTemp = new std::string[size];
    int* countArrTemp = new int[size];
    double* priceArrTemp = new double[size];

    for (int i = 0; i < size; i++)
    {
        idArrTemp[i] = test[i];
        nameArrTemp[i] = nameArr[i];
        countArrTemp[i] = countArr[i];
        priceArrTemp[i] = priceArr[i];
    }
    delete[] test;
    delete[] nameArr;
    delete[] countArr;
    delete[]priceArr;

    size--;
    test = new int[size];
    nameArr = new std::string[size];
    countArr = new int[size];
    priceArr = new double[size];

    int index = 0;
    std::cout << "Введите id для удаления товара: ";
    std::cin >> index;

    for (int i = 0, j = 0; i < size, j < size; j++, i++)
    {
        if (i == index - 1)
        {
            i++;
            test[j] = idArrTemp[j];
            nameArr[j] = nameArrTemp[i];
            countArr[j] = countArrTemp[i];
            priceArr[j] = priceArrTemp[i];
        }
        else
        {
            test[j] = idArrTemp[j];
            nameArr[j] = nameArrTemp[i];
            countArr[j] = countArrTemp[i];
            priceArr[j] = priceArrTemp[i];
        }
    }
    delete[] idArrTemp;
    delete[] nameArrTemp;
    delete[] countArrTemp;
    delete[]priceArrTemp;
}
