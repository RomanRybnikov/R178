all:: Game

Game: main.o Map.o Cell.o Loger.o LogPlayer.o Iterator.o AddCoinsCellLogic.o FailWinEndMapStrattegy.o HpCellLogic.o KillCellLogic.o WinEndMapStrattegy.o Player.o
	g++ main.o Map.o Cell.o Iterator.o AddCoinsCellLogic.o FailWinEndMapStrattegy.o HpCellLogic.o KillCellLogic.o WinEndMapStrattegy.o Player.o Loger.o LogPlayer.o -o Game
	
main.o: main.cpp Map.h Iterator.h
	g++ -c main.cpp

Iterator.o: Iterator.cpp Iterator.h Map.h Cell.h
	g++ -c Iterator.cpp

Map.o: Map.cpp Map.h Cell.h Iterator.h AddCoinsCellLogic.h HpCellLogic.h KillCellLogic.h
	g++ -c Map.cpp
	
Cell.o: Cell.cpp Cell.h CellTypes.h
	g++ -c Cell.cpp
	
AddCoinsCellLogic.o: AddCoinsCellLogic.cpp AddCoinsCellLogic.h Player.h
	g++ -c AddCoinsCellLogic.cpp

FailWinEndMapStrattegy.o: FailWinEndMapStrattegy.cpp FailWinEndMapStrattegy.h Player.h
	g++ -c FailWinEndMapStrattegy.cpp
	
HpCellLogic.o: HpCellLogic.cpp HpCellLogic.h Player.h KillCellLogic.h
	g++ -c HpCellLogic.cpp
	
KillCellLogic.o: KillCellLogic.cpp KillCellLogic.h Player.h
	g++ -c KillCellLogic.cpp
	
WinEndMapStrattegy.o: WinEndMapStrattegy.cpp WinEndMapStrattegy.h Player.h
	g++ -c WinEndMapStrattegy.cpp
	
Player.o: Player.cpp Player.h FailWinEndMapStrattegy.h WinEndMapStrattegy.h EndMapStrattegy.h Iterator.h
	g++ -c Player.cpp
	
Loger.o: Loger.cpp Loger.h
	g++ -c Loger.cpp

LogPlayer.o: LogPlayer.cpp LogPlayer.h Loger.h Player.h
	g++ -c LogPlayer.cpp

	
clean:
	rm -rf *.o Game
