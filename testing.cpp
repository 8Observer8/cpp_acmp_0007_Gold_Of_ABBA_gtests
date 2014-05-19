#include <gtest/gtest.h>
#include <string>
#include <stdexcept>

class LogicError : public std::logic_error {
public:

    LogicError( ) : std::logic_error( "" ) {

    }

    virtual const char *what( ) const throw () {
        return m_message.c_str( );
    }

    virtual ~LogicError( ) throw () {

    }

protected:
    std::string m_message;
};

class EmptyArgument : public LogicError {
public:

    EmptyArgument( ) {
        m_message = "Error: empty argument";
    }
};

class BadArgument : public LogicError {
public:

    BadArgument( const std::string &argument ) {
        m_message = "Error: bad argument " + argument;
    }
};

std::string theLagestNumber( std::string firstNumber,
                             std::string secondNumber,
                             std::string thirdNumber ) throw( EmptyArgument, BadArgument );

TEST( test001, exceptionTest ) {
    std::string firstNumber;
    std::string secondNumber = "5";
    std::string thirdNumber = "7";

    ASSERT_THROW({
                     theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 }, EmptyArgument);
}

TEST( test002, exceptionTest ) {
    std::string firstNumber = "5";
    std::string secondNumber;
    std::string thirdNumber = "7";

    ASSERT_THROW({
                     theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 }, EmptyArgument);
}

TEST( test003, exceptionTest ) {
    std::string firstNumber = "5";
    std::string secondNumber = "7";
    std::string thirdNumber;

    ASSERT_THROW({
                     theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 }, EmptyArgument);
}

TEST( test004, exceptionTest ) {
    std::string firstNumber = "1w1";
    std::string secondNumber = "555";
    std::string thirdNumber = "777";

    ASSERT_THROW({
                     theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 }, BadArgument);
}

TEST( test005, exceptionTest ) {
    std::string firstNumber = "111";
    std::string secondNumber = "5w5";
    std::string thirdNumber = "777";

    ASSERT_THROW({
                     theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 }, BadArgument);
}

TEST( test006, exceptionTest ) {
    std::string firstNumber = "111";
    std::string secondNumber = "555";
    std::string thirdNumber = "7w7";

    ASSERT_THROW({
                     theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 }, BadArgument);
}

TEST( test007, normalTest ) {
    std::string firstNumber = "111";
    std::string secondNumber = "555";
    std::string thirdNumber = "777";

    std::string actual;
    ASSERT_NO_THROW({
                     actual = theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 });

    std::string expected = "777";
    ASSERT_EQ( expected, actual );
}


TEST( test008, normalTest ) {
    std::string firstNumber = "777";
    std::string secondNumber = "555";
    std::string thirdNumber = "111";

    std::string actual;
    ASSERT_NO_THROW({
                     actual = theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 });

    std::string expected = "777";
    ASSERT_EQ( expected, actual );
}

TEST( test009, normalTest ) {
    std::string firstNumber = "111";
    std::string secondNumber = "777";
    std::string thirdNumber = "555";

    std::string actual;
    ASSERT_NO_THROW({
                     actual = theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 });

    std::string expected = "777";
    ASSERT_EQ( expected, actual );
}

TEST( test010, normalTest ) {
    std::string firstNumber = "189285";
    std::string secondNumber = "283";
    std::string thirdNumber = "4958439238923098349024";

    std::string actual;
    ASSERT_NO_THROW({
                     actual = theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 });

    std::string expected = "4958439238923098349024";
    ASSERT_EQ( expected, actual );
}

TEST( test011, normalTest ) {
    std::string firstNumber = "189285";
    std::string secondNumber = "4958439238923098349024";
    std::string thirdNumber = "283";

    std::string actual;
    ASSERT_NO_THROW({
                     actual = theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 });

    std::string expected = "4958439238923098349024";
    ASSERT_EQ( expected, actual );
}

TEST( test012, normalTest ) {
    std::string firstNumber = "4958439238923098349024";
    std::string secondNumber = "189285";
    std::string thirdNumber = "283";

    std::string actual;
    ASSERT_NO_THROW({
                     actual = theLagestNumber( firstNumber, secondNumber, thirdNumber );
                 });

    std::string expected = "4958439238923098349024";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
