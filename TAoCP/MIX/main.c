// https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/

/////////////////////////////////////////////////////////////////////////////////
//////////////////////  Interpreter / Emulator UI and IO ////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char *DECIMAL_REGISTER_OUTLINE[] = {"         Register A                             Register X",
"+---+----+----+----+----+----+       +---+----+----+----+----+----+",
"|SGN| A1 | A2 | A3 | A4 | A5 |       |SGN| X1 | X2 | X3 | X4 | X5 |",
"+---+----+----+----+----+----+       +---+----+----+----+----+----+",
"|   |    |    |    |    |    |       |   |    |    |    |    |    |",
"+---+----+----+----+----+----+       +---+----+----+----+----+----+"
"",
"",
"                   Over     Comp     Register J",
"                   +--+     +--+    +----+----+",
"                   |  |     |  |    | J1 | J2 |",
"                   +--+     +--+    +----+----+",
"                                    |    |    |",
"                                    +----+----+",
"",
"       I1                   I2                   I3",
"+---+-----+-----+    +---+-----+-----+    +---+-----+-----+",
"|SGN| I14 | I15 |    |SGN| I24 | I25 |    |SGN| I34 | I35 |",
"+---+-----+-----+    +---+-----+-----+    +---+-----+-----+",
"|   |     |     |    |   |     |     |    |   |     |     |",
"+---+-----+-----+    +---+-----+-----+    +---+-----+-----+",
"", 
"       I4                   I5                   I6",
"+---+-----+-----+    +---+-----+-----+    +---+-----+-----+",
"|SGN| I44 | I45 |    |SGN| I54 | I55 |    |SGN| I64 | I65 |",
"+---+-----+-----+    +---+-----+-----+    +---+-----+-----+",
"|   |     |     |    |   |     |     |    |   |     |     |",
"+---+-----+-----+    +---+-----+-----+    +---+-----+-----+",
};

const char *BINARY_REGISTER_OUTLINE[] = {"         Register A                                            Register X",
"+---+------+------+------+------+------+      +---+------+------+------+------+------+",
"|SGN|  A1  |  A2  |  A3  |  A4  |  A5  |      |SGN|  X1  |  X2  |  X3  |  X4  |  X5  |",
"+---+------+------+------+------+------+      +---+------+------+------+------+------+",
"|   |      |      |      |      |      |      |   |      |      |      |      |      |",
"+---+------+------+------+------+------+      +---+------+------+------+------+------+",
"",
"                   Over     Comp       Register J",
"                   +--+     +--+    +------+------+",
"                   |  |     |  |    |  J1  |  J2  |",
"                   +--+     +--+    +------+------+",
"                                    |      |      |",
"                                    +------+------+",
"",
"         I1                       I2                       I3",
"+---+-------+-------+    +---+-------+-------+    +---+-------+-------+",
"|SGN|  I14  |  I15  |    |SGN|  I24  |  I25  |    |SGN|  I34  |  I35  |",
"+---+-------+-------+    +---+-------+-------+    +---+-------+-------+",
"|   |       |       |    |   |       |       |    |   |       |       |",
"+---+-------+-------+    +---+-------+-------+    +---+-------+-------+",
"", 
"         I4                       I5                       I6",
"+---+-------+-------+    +---+-------+-------+    +---+-------+-------+",
"|SGN|  I44  |  I45  |    |SGN|  I54  |  I55  |    |SGN|  I64  |  I65  |",
"+---+-------+-------+    +---+-------+-------+    +---+-------+-------+",
"|   |       |       |    |   |       |       |    |   |       |       |",
"+---+-------+-------+    +---+-------+-------+    +---+-------+-------+",
};
