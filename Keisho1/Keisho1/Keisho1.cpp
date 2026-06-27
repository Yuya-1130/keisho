
#include <iostream>

//// 自動車クラス
//class Car
//{
//public:
//    Car() {
//        std::cout << "Carクラスのコンストラクタ" << std::endl;
//    }
//    virtual~Car() {
//        std::cout << "Carクラスのデストラクタ" << std::endl;
//    }
//
//   
//    
//
//public:
//
//    // エンジンを始動する
//    void startEngine()
//    {
//        std::cout << "エンジンを始動する" << std::endl;
//        running_ = true;
//    }
//
//    // エンジンを停止する
//    void stopEngine()
//    {
//        std::cout << "エンジンを停止する" << std::endl;
//        running_ = false;
//    }
//
//    // （何かを）運ぶ
//    virtual void carry() = 0;
//
//protected:
//    bool running_ = false; // エンジンが動いている
//};
//
//// タンクローリークラス
//class Tank : public Car
//{
//public:
//    Tank() {
//        std::cout << "Tankクラスのコンストラクタ" << std::endl;
//    }
//    ~Tank() {
//        std::cout << "Tankクラスのデストラクタ" << std::endl;
//    }
//
//    // 派生クラスで純粋仮想関数をオーバーライドしなければインスタンス化ができない
//    // 普通の仮想関数なら問題ないが純粋仮想関数のほうが具体的にできる
//    void carry() override
//    {
//        // 中身はタンクローリー用
//        std::cout << "燃料を運ぶ" << std::endl;
//    }
//
//public:
//    // 燃料を送出する
//    void pumpOut()
//    {
//        // running_ を宣言しているのは Car クラスだが、
//        // Tank クラスが Car クラスを継承している為利用できる
//        if (running_) {
//            std::cout << "エンジンが動いているので燃料の送出は危険" << std::endl;
//        }
//        else
//        {
//            std::cout << "燃料を送出する" << std::endl;
//        }
//    }
//
//};
//
//// エントリー関数
//int main()
//{
//    // 純粋仮想関数にするとCarのインスタンス化ができない
//    //Car car;
//    //Car* p = new Car;
//   
//    //// 車のエンジンを始動する
//    //car.startEngine();
//    //car.carry();
//
//    Tank* tank = new Tank;
//    // Tank のアドレスを Car ポインタで受け取る事が出来る
//    Car* car = tank;
//
//    // Car の carry() が呼び出される
//    car->carry();
//    // Car に 宣言されていないのでコンパイルエラー
//    //car->pumpOut();
//    //tank = (Tank*)car;
//
//    // startEngine() と stopEngine() を定義しているのは Car クラスだが、
//    // Tank クラスが Car クラスを継承している為利用できる
//    /*tank.startEngine();
//    tank.stopEngine();
//    tank.carry();*/
//
//    //// 当然 Tank クラスで定義した関数は呼び出せる
//    //tank.pumpOut();
//    delete car;
//}

// 多態性のコード
class Car
{
public:
   virtual void carry() {
        std::cout << "何かを運ぶ" << std::endl;
    }
};

// タンクローリークラス
class Tank : public Car
{
public:
    void carry() override {
        std::cout << "燃料を運ぶ" << std::endl;
    }
};

// ダンプカークラス
class Dump : public Car
{
public:
    void carry() override {
        std::cout << "土砂を運ぶ" << std::endl;
    }
};

// エントリー関数
int main()
{ 
    // インスタンスとは違うが、基底クラスポインタの配列をすべて含める
    Car* cars[] = { new Car, new Tank, new Dump };
    // 配列のループでインスタンス毎の関数を呼び出す
    for (int i = 0; i < 3; ++i){
        cars[i]->carry();
    }

    for (int i = 0; i < 3; ++i){
        delete cars[i];
        cars[i] = nullptr;
    }
   
}
