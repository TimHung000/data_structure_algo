#include <iostream>
#include <string>

class Terminal {
    private:
        enum Mode {OverWrite, Insert};
        char** display;
        int rows;
        int cols;
        int currentRow;
        int currentCol;
        Mode mode;
    public:
        void setCurrentRow(int row);
        void setCurrentCol(int col);
        void setMode(Terminal::Mode mode);
        int getRows();
        int getCols();
        int getCurrentRow();
        int getCurrentCol();
        Mode getMode();
        void reset();
        void show();
        void write(char c);
        void control(char c);
        Terminal(int rows, int cols);
        ~Terminal();
};

Terminal::Terminal(int rows, int cols)
    : rows(rows), cols(cols), currentRow(0), currentCol(0), mode(Mode::OverWrite)
{
    display = new char *[rows];
    for(int i = 0; i < rows; ++i)
    {
        display[i] = new char[cols];
    }
}

Terminal::~Terminal()
{
    int rows = sizeof(display) / sizeof(display[0]);
    int cols = sizeof(display[0]) / sizeof(char);
    for(int i = 0; i < rows; ++i)
        delete[] display[i];

    delete[] display;
}

void Terminal::setCurrentRow(int row)
{
    currentRow = row;
}

void Terminal::setCurrentCol(int col)
{
    currentCol = col;
}

void Terminal::setMode(Terminal::Mode mode)
{
    mode = mode;
}

int Terminal::getRows(){ return rows; }
int Terminal::getCols(){ return cols; }
int Terminal::getCurrentRow(){ return currentRow; }
int Terminal::getCurrentCol(){ return currentCol; }
Terminal::Mode Terminal::getMode(){ return mode; }
void Terminal::reset()
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            display[i][j] = ' ';
        }
    }
    currentRow = currentCol = 0;
}

void Terminal::show()
{
    std::cout << "+----------+" << "\n";
    for(int i = 0; i < rows; ++i)
    {
        std::cout << "|";
        for(int j = 0; j < cols; ++j)
        {
            std::cout << display[i][j];
        }
        std::cout << "|" << "\n";
    }
    std::cout << "+----------+" << "\n";
}

void Terminal::write(char c)
{
    if(mode == Mode::Insert)
    {
        for(int i = 9; i > currentCol; --i)
            display[currentRow][i] = display[currentRow][i-1];
    }
    display[currentRow][currentCol] = c;

    if(currentCol < cols - 1) ++currentCol;
}

void Terminal::control(char c)
{
	switch (c) {
		case 'r':
			if (currentCol < cols - 1) {
				currentCol += 1;
			}
		    break;
		case 'l':
			if (currentCol > 0) {
			    currentCol-= 1;
			}
            break;
		case 'd':
			if (currentRow < rows - 1) {
				currentRow += 1;
			}
            break;
		case 'u':
			if (currentRow > 0) {
				currentRow -= 1;
			}
            break;
		case 'b':
			currentCol = 0;
            break;
		case 'h':
			currentRow = 0;
			currentCol = 0;
            break;
		case 'c':
            {
                int tmpRow = currentRow;
                int tmpCol = currentCol;
                reset();
                currentRow = tmpRow;
                currentCol = tmpCol;
            }
            break;
		case 'e':
            {
                for (int i = currentCol; i < cols; ++i) {
                    display[currentRow][i] = ' ';
                }
            }
            break;
		case 'i':
			mode = Mode::Insert;
            break;
		case 'o':
			mode = Mode::OverWrite;
            break;
	}
}


int main(int argc, char** argv)
{
    int caseNum = 1;
    int line;
    while(std::cin >> line)
    {
        std::cin.ignore();
        if(line == 0) break;
        Terminal myTerminal(10, 10);
        myTerminal.reset();
        for(int i = 0; i < line; ++i)
        {
            std::string str;
            std::getline(std::cin, str);
            for(int c = 0; c < str.length(); ++c)
            {
                if(str[c] == '^')
                {
                    if(str[c+1] >= '0' && str[c+1] <= '9')
                    {
                        myTerminal.setCurrentRow(str[c+1] - '0');
                        myTerminal.setCurrentCol(str[c+2] - '0');
                        c += 2;
                    }
                    else if(str[c+1] == '^')
                    {
                        myTerminal.write(str[c+1]);
                        ++c;
                    }
                    else
                    {
                        myTerminal.control(str[c+1]);
                        ++c;
                    }
                }
                else
                {
                    myTerminal.write(str[c]);
                }
            }
        }
        std::cout << "Case " << caseNum++ << "\n";
        myTerminal.show();
    }
    return 0;
}
