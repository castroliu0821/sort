#include <iostream>
#include <google/include/gtest/gtest.h>
#include <google/include/gmock/gmock.h>

#include "quicksort.h"
#include "heapsort.h"
#include <hashtable.h>

using namespace std;

class GloablEnviroment : public ::testing::Environment {
public:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

class quicksortCase : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

class heapsortCase : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
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

TEST_F(quicksortCase, case_1_arr) {
    int arr[1] = {0};
    int buf[1] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}

TEST_F(quicksortCase, case_2_arr) {
    int arr[3] = {3, 1, 2};
    int buf[3] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}

TEST_F(quicksortCase, case_10_arr) {
    int arr[10] = {3, 1, 2, 6, 9, 10, 5, 7, 4, 8};
    int buf[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}

TEST_F(heapsortCase, case_1_arr) {
    int arr[1] = {0};
    int buf[1] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}

TEST_F(heapsortCase, case_2_arr) {
    int arr[3] = {3, 1, 2};
    int buf[3] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}

TEST_F(heapsortCase, case_10_arr) {
    int arr[10] = {3, 1, 2, 6, 9, 10, 5, 7, 4, 8};
    int buf[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, len);
    EXPECT_TRUE(0 == memcmp(arr, buf, sizeof(arr)));
}
