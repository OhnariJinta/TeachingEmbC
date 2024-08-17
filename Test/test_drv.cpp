// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
#include "fff.h" //テストフォルダ直下にでも置いておく
DEFINE_FFF_GLOBALS;

// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
#include "../src/APP/INC/add.h"
#include "../src/DRV/INC/sub.h"
}

FAKE_VALUE_FUNC(int, add, int, int);

// sub_test(fixtureName)はテストケース群をまとめるグループ名と考えればよい、任意の文字列
// それ以外のclass～testing::Testまではおまじないと考える
class sub_test : public ::testing::Test {
protected:
    // fixtureNameでグループ化されたテストケースはそれぞれのテストケース実行前に
    // この関数を呼ぶ。共通の初期化処理を入れておくとテストコードがすっきりする
    virtual void SetUp(){
        add_fake.call_count = 0;
    }
    // SetUpと同様にテストケース実行後に呼ばれる関数。共通後始末を記述する。
    virtual void TearDown(){
    }
};

TEST_F(sub_test, subOK){
    add_fake.return_val = 3;
    EXPECT_EQ(-1, sub(1,2));
    EXPECT_EQ(add_fake.call_count, 1);
}

TEST_F(sub_test, subNG){
    EXPECT_EQ(add_fake.call_count, 0);
    EXPECT_NE(5, sub(1,2));
}