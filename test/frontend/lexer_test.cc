#include <gtest/gtest.h>
#include <lexer.hh>

// Test the lexer constructor 

TEST(lexer, constructor){
    frontend::lexer l("Hello World");
    EXPECT_EQ(l.tokens.size(), 2);
    EXPECT_EQ(l.tokens[0], "Hello");
    EXPECT_EQ(l.tokens[1], "World");
}

TEST(lexer, empty){
    frontend::lexer l("");
    EXPECT_EQ(l.tokens.size(), 0);
}

TEST(lexer, single){
    frontend::lexer l("Hello");
    EXPECT_EQ(l.tokens.size(), 1);
    EXPECT_EQ(l.tokens[0], "Hello");
}

TEST(lexer, multiple_spaces){
    frontend::lexer l("fun x -> (x + 1)");
    EXPECT_EQ(l.tokens.size(), 2);
    EXPECT_EQ(l.tokens[0], "fun");
    EXPECT_EQ(l.tokens[1], "x");
    EXPECT_EQ(l.tokens[2], "->");
    EXPECT_EQ(l.tokens[3], "(");
    EXPECT_EQ(l.tokens[4], "x");
    EXPECT_EQ(l.tokens[5], "+");
    EXPECT_EQ(l.tokens[6], "1");
    EXPECT_EQ(l.tokens[7], "'");
}

int main(){
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}