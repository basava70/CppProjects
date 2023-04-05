// Tic Tac Toe  game started development on 20 March
#include<iostream>
#include<string>
#include<vector>

// Class with gamer info
class Gamer{
   std::string name,
	  mark;
   int turn_count;
   public:

   void input_name(std::string name_)
   {
	  name = name_;
   }
   void input_mark(std::string mark_)
   {
	  mark = mark_;
   }
   void update_turn_count()
   {
	  turn_count++;
   }

   std::string get_name()
   {
	  return name;
   }
   std::string get_mark()
   {
	  return mark;
   }
   int get_turn_count()
   {
	  return turn_count;
   }
};

class TicTacToe
{
   void print_win()
   {
	  std::cout << current_gamer.get_name() << " has won the game" << std::endl;
   }

   bool is_win(Gamer curr_gamer)
   {
	  std::string curr_mark = curr_gamer.get_mark();
	  int curr_turn_count = curr_gamer.get_turn_count();
	  if(curr_turn_count < 3) return false;
	  else if(GameMatrix[0] == curr_mark && GameMatrix[1] == curr_mark && GameMatrix[2] == curr_mark)
		 return true;
	  else if(GameMatrix[3] == curr_mark && GameMatrix[4] == curr_mark && GameMatrix[5] == curr_mark)
		 return true;
	  else if(GameMatrix[6] == curr_mark && GameMatrix[7] == curr_mark && GameMatrix[8] == curr_mark)
		 return true;
	  else if(GameMatrix[0] == curr_mark && GameMatrix[3] == curr_mark && GameMatrix[6] == curr_mark)
		 return true;
	  else if(GameMatrix[1] == curr_mark && GameMatrix[4] == curr_mark && GameMatrix[7] == curr_mark)
		 return true;
	  else if(GameMatrix[2] == curr_mark && GameMatrix[5] == curr_mark && GameMatrix[8] == curr_mark)
		 return true;
	  else if(GameMatrix[0] == curr_mark && GameMatrix[4] == curr_mark && GameMatrix[8] == curr_mark)
		 return true;
	  else if(GameMatrix[2] == curr_mark && GameMatrix[4] == curr_mark && GameMatrix[6] == curr_mark)
		 return true;
	  else
			return false;
   }

   void print()
   {
	  system("clear");
	  std::string line(50, '_'), // for decorative purposes
		 line_small(3, '=');
	  // getting info
	  std::string name_1 = gamer_1.get_name(),
		 name_2 = gamer_2.get_name(),
		 mark_1 = gamer_1.get_mark(),
		 mark_2 = gamer_2.get_mark();

	  std::string current_name = current_gamer.get_name(),
		 current_mark = current_gamer.get_mark();

	  std::cout << line << std::endl;
	  std::cout << name_1 << "==> X" << "   " << name_2 << "==> 0" << std::endl;
	  std::cout << std::endl;
	  std::cout << " " << GameMatrix[0] << " || " << GameMatrix[1] << " || " << GameMatrix[2] << "" << std::endl;
	  std::cout << line_small << "||" << line_small << "||" << line_small << std::endl;
	  std::cout << " " << GameMatrix[3] << " || " << GameMatrix[4] << " || " << GameMatrix[5] << "" << std::endl;
	  std::cout << line_small << "||" << line_small << "||" << line_small << std::endl;
	  std::cout << " " << GameMatrix[6] << " || " << GameMatrix[7] << " || " << GameMatrix[8] << "" << std::endl;
	  std::cout << line_small << "||" << line_small << "||" << line_small << std::endl;
   }

   void get_input()
   {
	  std::string line(50, '_');
	  std::cout << line << std::endl;
	  int block_num;
      current_gamer = (turn % 2) ? gamer_1 : gamer_2;
	  std::string current_name = current_gamer.get_name();
	  std::cout << current_name << "'s turn, please choose a block" << std::endl;
	  std::cin >> block_num;
	  block_num -= 1;
	  if(block_num < 0 || block_num > 8)
	  {
		 std::cout << "Input block is out of bounds"<< std::endl;
		 get_input();
	  }

	  if (is_input[block_num])
	  {
		 GameMatrix[block_num] = current_gamer.get_mark();
	     total_turn_count++;
		 is_input[block_num] = false;
		 current_gamer.update_turn_count();
		 bool win = is_win(current_gamer);
	     print();
		 if(win) print_win();
		 else
		 {
			if (total_turn_count == 9)
			{
			   std::cout << "Game is a draw" << std::endl;
			   return;
			}
			turn += 1;
			get_input();
		 }
	  }
	  else
	  {
		 std::cout << "Error !! Wrong input, block already in use" << std::endl;
		 get_input();
	  }

   }

   // Game Matrix to store the inputs and display
   // acts as the UI
   std::vector<std::string> GameMatrix =
   {
	  "1", "2", "3",
	  "4", "5", "6",
	  "7", "8", "9"
   };

   Gamer gamer_1, gamer_2; // gamers 1 and two
   int turn; // selects the gamer whose turn to play
   int total_turn_count;
   Gamer current_gamer;
   // true implies GameMatrix[i] is ready for input
   std::vector<bool> is_input{std::vector<bool>(9, true)};


   public:
   // Initialise the game
   void play()
   {
	  std::string temp_str;
	  // Getting info of the gamers and initializing details
	  std::cout << "Enter first gamer's name " << std::endl;
	  std::cin >> temp_str;
	  gamer_1.input_name(temp_str);
	  gamer_1.input_mark("X");

	  std::cout << "Enter second gamer's name " << std::endl;
	  std::cin >> temp_str;
	  gamer_2.input_name(temp_str);
	  gamer_2.input_mark("O");

	  turn = 1; // setting turn to gamer_1
	  total_turn_count = 0;
      print();
      get_input();

   }

};


int main()
{
   TicTacToe tic_tac_toe;
   tic_tac_toe.play();
}
