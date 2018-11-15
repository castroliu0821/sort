#include <iostream>
#include <google/include/gtest/gtest.h>
#include <google/include/gmock/gmock.h>

#include "quicksort.h"
#include <hashtable.h>

using namespace std;

class GloablEnviroment : public ::testing::Environment {
public:
    virtual void SetUp() {
        cout << "Gobal SetUp" << endl;
    }

    virtual void TearDown() {
        cout << "Global TearDown" << endl;
    }
};


class QsortCase : public ::testing::Test {
protected:
    virtual void SetUp() {
        cout << "Test case set up"<< endl;
    }

    virtual void TearDown() {
        cout << "Test case Tear down"<< endl;
    }
};

int main(int argc, char** argv)
{
    ::testing::AddGlobalTestEnvironment(new GloablEnviroment);
    ::testing::InitGoogleTest(&argc, argv);

    int result = RUN_ALL_TESTS();

    cout << "Run result: " << result << endl;

    return 0;
}

TEST_F(QsortCase, case_1_arr) {
    int arr[1] = {0};
    int buf[1] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}

TEST_F(QsortCase, case_2_arr) {
    int arr[3] = {3, 1, 2};
    int buf[3] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}

TEST_F(QsortCase, case_10_arr) {
    int arr[10] = {3, 1, 2, 6, 9, 10, 5, 7, 4, 8};
    int buf[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}
