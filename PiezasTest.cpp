/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};
    /* [row][column] */
    /* [2,0][2,1][2,2][2,3]
       [1,0][1,1][1,2][1,3]
       [0,0][0,1][0,2][0,3] */

TEST(PiezasTest, sanity_check)
{
	ASSERT_TRUE(true);
}

/* Tests dropPiece for x */
TEST(PiezasTest, dropPiece_x_check)
{
    Piezas obj;
    ASSERT_EQ(obj.dropPiece(0), X);
}

/* Tests dropPiece for o */
TEST(PiezasTest, dropPiece_o_check)
{
    Piezas obj;
    obj.dropPiece(1);
    ASSERT_EQ(obj.dropPiece(0), O);
}

/* Tests dropPiece for high column coord */
TEST(PiezasTest, dropPiece_invalid_high_column)
{
    Piezas obj;
    ASSERT_EQ(obj.dropPiece(4), Invalid);
}

/* Tests dropPiece for low column coord */
TEST(PiezasTest, dropPiece_invalid_low_column)
{
    Piezas obj;
    ASSERT_EQ(obj.dropPiece(-1), Invalid);
}

/* Tests dropPiece for full row */
TEST(PiezasTest, dropPiece_full_row)
{
    Piezas obj;
    obj.dropPiece(1);
    obj.dropPiece(1);
    obj.dropPiece(1);
    ASSERT_EQ(obj.dropPiece(1), Blank);
}

/* Tests pieceAt after constructor*/
TEST(PiezasTest, pieceAt_random_coord)
{
    Piezas obj;
    ASSERT_EQ(obj.pieceAt(2, 1), Blank);
}

/* Tests pieceAt invalid coordinates */
TEST(PiezasTest, pieceAt_invalid_high_row_coord) {
    Piezas obj;
    ASSERT_EQ(obj.pieceAt(3, 0), Invalid);
}

/* Tests pieceAt invalid coordinates */
TEST(PiezasTest, pieceAt_invalid_low_row_coord) {
    Piezas obj;
    ASSERT_EQ(obj.pieceAt(-1, 0), Invalid);
}

/* Tests pieceAt invalid coordinates */
TEST(PiezasTest, pieceAt_invalid_high_column_coord) {
    Piezas obj;
    ASSERT_EQ(obj.pieceAt(0, 4), Invalid);
}

/* Tests pieceAt invalid coordinates */
TEST(PiezasTest, pieceAt_invalid_low_column_coord) {
    Piezas obj;
    ASSERT_EQ(obj.pieceAt(0, -1), Invalid);
}

/* Tests pieceAt x check */
TEST(PiezasTest, pieceAt_x_check) {
    Piezas obj;
    obj.dropPiece(0);
    ASSERT_EQ(obj.pieceAt(0, 0), X);
}

/* Tests pieceAt o check */
TEST(PiezasTest, pieceAt_o_check) {
    Piezas obj;
    obj.dropPiece(0);
    obj.dropPiece(0);
    ASSERT_EQ(obj.pieceAt(1, 0), O);
}

/* Tests pieceAt multiple checks */
TEST(PiezasTest, pieceAt_multiple_checks) {
    Piezas obj;
    obj.dropPiece(0);
    obj.dropPiece(0);
    bool x = obj.pieceAt(0, 0) == X;
    bool o = obj.pieceAt(1, 0) == O;
    ASSERT_TRUE(x && o);
}

/* Tests if constructor built board correctly */
TEST(PiezasTest, constructor_blank_grid)
{
    Piezas obj;
    bool _00 = obj.pieceAt(0, 0) == Blank;
    bool _10 = obj.pieceAt(1, 0) == Blank;
    bool _20 = obj.pieceAt(2, 0) == Blank;
    bool _01 = obj.pieceAt(0, 1) == Blank;
    bool _11 = obj.pieceAt(1, 1) == Blank;
    bool _21 = obj.pieceAt(2, 1) == Blank;
    bool _02 = obj.pieceAt(0, 2) == Blank;
    bool _12 = obj.pieceAt(1, 2) == Blank;
    bool _22 = obj.pieceAt(2, 2) == Blank;
    bool _03 = obj.pieceAt(0, 3) == Blank;
    bool _13 = obj.pieceAt(1, 3) == Blank;
    bool _23 = obj.pieceAt(2, 3) == Blank;
	ASSERT_TRUE(_00 && _10 && _20 && _01 && _11 && _21 && _02 && _12 && _22 && _03 && _13 && _23);
}

/* Tests reset */
TEST(PiezasTest, reset)
{
    Piezas obj;
    obj.dropPiece(0);
    obj.reset();
    ASSERT_EQ(obj.pieceAt(0,0), Blank);
}

/* Tests gameState for Invalid when game isn't over */
TEST(PiezasTest, gameState_game_not_over_and_blank)
{
    Piezas obj;
    ASSERT_EQ(obj.gameState(), Invalid);
}

/* Tests gameState for Invalid when game isn't over */
TEST(PiezasTest, gameState_game_not_over)
{
    Piezas obj;
    obj.dropPiece(0);
    ASSERT_EQ(obj.gameState(), Invalid);
}

/* Tests gameState for when x has won the game */
TEST(PiezasTest, gameState_x_win)
{
    /* [row][column] */
    /*  0  1  2  3 */
    /* [O][O][O][X]
       [O][X][O][O]
       [X][X][X][X] */
    Piezas obj;
    obj.dropPiece(0); // X
    obj.dropPiece(0); // O
    obj.dropPiece(1); // X
    obj.dropPiece(0); // O
    obj.dropPiece(2); // X
    obj.dropPiece(2); // O
    obj.dropPiece(3); // X
    obj.dropPiece(2); // O
    obj.dropPiece(1); // X
    obj.dropPiece(3); // O
    obj.dropPiece(3); // X
    obj.dropPiece(1); // O

    ASSERT_EQ(obj.gameState(), X);
}

/* Tests gameState for when o has won the game */
TEST(PiezasTest, gameState_o_win)
{
    /* [row][column] */
    /*  0  1  2  3 */
    /* [X][O][X][X]
       [O][O][O][O]
       [X][O][X][X] */
    Piezas obj;
    obj.dropPiece(0); // X
    obj.dropPiece(0); // O
    obj.dropPiece(3); // X
    obj.dropPiece(1); // O
    obj.dropPiece(2); // X
    obj.dropPiece(1); // O
    obj.dropPiece(0); // X
    obj.dropPiece(2); // O
    obj.dropPiece(2); // X
    obj.dropPiece(3); // O
    obj.dropPiece(3); // X
    obj.dropPiece(1); // O

    ASSERT_EQ(obj.gameState(), O);
}

/* Tests gameState for when there is a tie */
TEST(PiezasTest, gameState_tie_game)
{
    /* [row][column] */
    /*  0  1  2  3 */
    /* [O][O][O][O]
       [O][X][O][X]
       [X][X][X][X] */
    Piezas obj;
    obj.dropPiece(0); // X
    obj.dropPiece(0); // O
    obj.dropPiece(1); // X
    obj.dropPiece(0); // O
    obj.dropPiece(2); // X
    obj.dropPiece(2); // O
    obj.dropPiece(3); // X
    obj.dropPiece(2); // O
    obj.dropPiece(1); // X
    obj.dropPiece(1); // O
    obj.dropPiece(3); // X
    obj.dropPiece(3); // O
    ASSERT_EQ(obj.gameState(), Blank);
}
