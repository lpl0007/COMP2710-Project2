//FILENAME: project2_Louque_lpl0007.cpp
//AUTHOR: Lanie Louque (lpl0007)
//COMPILE: g++ project2_Louque_lpl0007.cpp
//SOURCES:
/*NONE*/

#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <iostream>
using namespace std;

bool at_least_two_alive(bool AAlive, bool BAlive, bool CAlive) {
	if ((AAlive && BAlive) || (AAlive && CAlive) || (BAlive && CAlive)) {
                return true;
        }
        else {
                return false;
	}
}

void test_at_least_two_alive() {
	cout <<	"\tCase 1: Aaron alive, Bob alive, Charlie alive" << endl;
	assert(true == at_least_two_alive(true, true, true));
	cout << "Case passed..." << endl;
        cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive" << endl;
        assert(true == at_least_two_alive(false, true, true));
        cout << "Case passed..." << endl;
	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive" << endl;
        assert(true == at_least_two_alive(true, false, true));
        cout << "Case passed..." << endl;
	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead" << endl;
        assert(true == at_least_two_alive(true, true, false));
        cout << "Case passed..." << endl;
	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive" << endl;
        assert(false == at_least_two_alive(false, false, true));
        cout << "Case passed..." << endl;
	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead" << endl;
        assert(false == at_least_two_alive(false, true, false));
        cout << "Case passed..." << endl;
        cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead" << endl;
        assert(false == at_least_two_alive(true, false, false));
        cout << "Case passed..." << endl;
        cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead" << endl;
        assert(false == at_least_two_alive(false, false, false));
        cout << "Case passed..." << endl;
}

void aaron_shoots1(bool& BAlive, bool& CAlive) {
	if (CAlive) {
		cout << "\t\tAaron is shooting at Charlie" << endl;
	}
	else if (BAlive) {
		cout << "\t\tAaron is shooting at Bob" << endl;
	}
	if ((rand()%100) <= 33) {
		cout << "\t\tHit the target" << endl;
		if (CAlive) {
			CAlive = false;
		}
		else if (BAlive) {
			BAlive = false;
		}
	}
}

void test_aaron_shoots1() {
	bool b, c = true;
	cout << "\tCase 1: Bob alive, Charlie alive" << endl;
	aaron_shoots1(b, c);
        cout << "Case passed..." << endl;
        cout << "\tCase 2: Bob dead, Charlie alive" << endl;
        b = false;
	c = true;
	aaron_shoots1(b, c);
        cout << "Case passed..." << endl;
        cout << "\tCase 3: Bob alive, Charlie dead" << endl;
        b = true;
	c = false;
	aaron_shoots1(b, c);
        cout << "Case passed..." << endl;
}

void bob_shoots(bool& AAlive, bool& CAlive) {
        if (CAlive) {
                cout << "\t\tBob is shooting at Charlie" << endl;
        }
        else if (AAlive) {
                cout << "\t\tBob is shooting at Aaron" << endl;
        }
        if ((rand()%100) <= 50) {
                cout << "\t\tHit the target" << endl;
                if (CAlive) {
                        CAlive = false;
                }
                else if (AAlive) {
                        AAlive = false;
                }
	}
}

void test_bob_shoots() {
	bool a, c = true;
	cout << "\tCase 1: Aaron alive, Charlie alive" << endl;
	bob_shoots(a, c);
        cout << "Case passed..." << endl;
        a = false;
	c = true;
	cout << "\tCase 2: Aaron dead, Charlie alive" << endl;
        bob_shoots(a, c);
        cout << "Case passed..." << endl;
        a = true;
	c = false;
	cout << "\tCase 3: Aaron alive, Charlie dead" << endl;
        bob_shoots(a, c);
        cout << "Case passed..." << endl;
}

void charlie_shoots(bool& AAlive, bool& BAlive) {
        if (BAlive) {
                cout << "\t\tCharlie is shooting at Bob" << endl;
        }
        else if (AAlive) {
                cout << "\t\tCharlie is shooting at Aaron" << endl;
        }
        cout << "\t\tHit the target" << endl;
        if (BAlive) {
        	BAlive = false;
        }
        else if (AAlive) {
                AAlive = false;
        }
}

void test_charlie_shoots() {
	bool a, b = true;
	cout << "\tCase 1: Aaron alive, Bob alive" << endl;
	charlie_shoots(a, b);
        cout << "Case passed..." << endl;
        a = false;
	b = true;
	cout << "\tCase 2: Aaron dead, Bob alive" << endl;
        charlie_shoots(a, b);
        cout << "Case passed..." << endl;
        a = true;
	b = false;
	cout << "\tCase 3: Aaron alive, Bob dead" << endl;
        charlie_shoots(a, b);
        cout << "Case passed..." << endl;
}

void aaron_shoots2(bool &BAlive, bool &CAlive) {
	if (BAlive && CAlive) {
		cout << "\t\tAaron intentionally misses his first shot" << endl;
		cout << "\t\tBoth Bob and Charlie are alive" << endl;
	}
	else if (CAlive) {
		cout << "\t\tAaron is shooting at Charlie" << endl;
		if ((rand()%100) <= 33) {
			cout << "\t\tHit the target" << endl;
			CAlive = false;
		}
	}
	else {
		cout << "\t\tAaron is shooting at Bob" << endl;
                if ((rand()%100) <= 33) {
                        cout << "\t\tHit the target" << endl;
                        BAlive = false;
                }
	}
}

void test_aaron_shoots2() {
	bool b, c = true;
	cout << "\tCase 1: Bob alive, Charlie alive" << endl;
	aaron_shoots2(b, c);
        cout << "Case passed..." << endl;
        b = false;
	c = true;
	cout << "\tCase 2: Bob dead, Charlie alive" << endl;
        aaron_shoots2(b, c);
        cout << "Case passed..." << endl;
	b = true;
	c = false;
	cout << "\tCase 3: Bob alive, Charlie dead" << endl;
        aaron_shoots2(b, c);
        cout << "Case passed..." << endl;
}

int main() {
	srand(time(0));

	cout << "***Welcome to Louque's Duel Simulator***";	
	cout << "Unit Testing 1: Function - at_least_two_alive()" << endl;
	test_at_least_two_alive();
	cout << "Press any key to continue..." << endl;
	cin.ignore().get();
        
	cout << "Unit Testing 2: Function - Aaron_shoots1(bob, charlie)" << endl;
        test_aaron_shoots1();
        cout << "Press any key to continue..." << endl;
        cin.ignore().get();

        cout << "Unit Testing 3: Function - Bob_shoots(aaron, charlie)" << endl;
        test_bob_shoots();
        cout << "Press any key to continue..." << endl;
        cin.ignore().get();

        cout << "Unit Testing 4: Function - Charlie_shoots(aaron, bob)" << endl;
        test_charlie_shoots();
        cout << "Press any key to continue..." << endl;
        cin.ignore().get();

        cout << "Unit Testing 5: Function - Aaron_shoots2(bob, charlie)" << endl;
        test_aaron_shoots2();
        cout << "Press any key to continue..." << endl;
        cin.ignore().get();
	
	cout << "Ready to test strategy 1 (run 10000 times):" << endl;
	cout << "Press any key to continue..." << endl;
        cin.ignore().get();
	
        bool aaron = true;
        bool bob = true;
        bool charlie = true;
	
	float AWon1, BWon, CWon, AWon2 = 0;
	int duel = 1;
	int dueler = 1;
	int total = 10000;
	
	while (duel <= total) {
		while (at_least_two_alive(aaron, bob, charlie)) {
			if(dueler == 1) {
				if(aaron) {
					aaron_shoots1(bob, charlie);
				}
				dueler++;
			}
			else if (dueler == 2) {
				if (bob) {
					bob_shoots(aaron, charlie);
				}
				dueler++;
			}
			else {
				if (charlie) {
					charlie_shoots(aaron, bob);
				}
				dueler = 1;
			}
		}
                if(dueler == 2) {
                        AWon1++;
                }
                else if (dueler == 3) {
                        BWon++;
                }
                else {
                        CWon++;
                }
		duel++;
		dueler = 1;
		aaron = true;
		bob = true;
		charlie = true;
	}
	
	cout << "Aaron won "<< AWon1 << "/" << total << " duels or " << (AWon1/total*100) << "%" << endl;
	cout << "Bob won "<< BWon << "/" << total << " duels or " << (BWon/total*100) << "%" << endl;
	cout << "Charlie won "<< CWon << "/" << total << " duels or " << (CWon/total*100) << "%" << endl;
	
	BWon = 0;
	CWon = 0;
	duel = 1;
	cout << "Ready to test strategy 2 (run 10000 times):" << endl;
	cout << "Press any key to continue..." << endl;
        cin.ignore().get();
	
        while (duel <= total) {
                while (at_least_two_alive(aaron, bob, charlie)) {
                        if(dueler == 1) {
                                if(aaron) {
                                        aaron_shoots2(bob, charlie);
                                }
                                dueler++;
                        }
                        else if (dueler == 2) {
                                if (bob) {
                                        bob_shoots(aaron, charlie);
                                }
                                dueler++;
                        }
                        else {
                                if (charlie) {
                                        charlie_shoots(aaron, bob);
                                }
                                dueler = 1;
                        }
                }
		if(dueler == 2) {
			AWon2++;
		}
		else if (dueler == 3) {
			BWon++;
		}
		else {
			CWon++;
		}
                duel++;
		dueler = 1;
                aaron = true;
                bob = true;
                charlie = true;
        }
 
	cout << "Aaron won "<< AWon2 << "/" << total << " duels or " << (AWon2/total*100) << "%" << endl;
        cout << "Bob won "<< BWon << "/" << total << " duels or " << (BWon/total*100) << "%" << endl;
	cout << "Charlie won "<< CWon << "/" << total << " duels or " << (CWon/total*100) << "%" << endl;
	
	if (AWon2 > AWon1) {
		cout << "Strategy 2 is better than strategy 1" << endl;
	}
	else {
		cout << "Strategy 1 is better than strategy 2" << endl;
	}
}
