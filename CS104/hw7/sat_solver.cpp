#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "avlbst.h"

using namespace std;

size_t check_correct_clause(AVLTree<int, int>& sol, map<int, set<int> >& all_clauses);
bool solveHelper(AVLTree<int, int>& sol, map<int, set<int> >& all_clauses, size_t curr_var);
bool isValid(AVLTree<int, int>& sol, map<int, set<int> >& all_clauses, size_t curr_var);
void printSolution(AVLTree<int, int>& sol, ofstream& ofile);

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Usage ./sat_solver input_file output_file" << endl;
  }

  ifstream ifile(argv[1]);
  if(ifile.fail())
  {
  	cerr << "Cannot open the file." << endl;
  	return 1;
  }

  string line;
  do{
  	getline(ifile, line, '\n');
  }
  while(line[0] == 'c');
  
  int num_vars, num_clauses;
  string temp1, temp2;
  stringstream ss(line);
  ss >> temp1 >> temp2 >> num_vars >> num_clauses;

  map<int, set<int> > all_clauses;
  for(int i = 0; i < num_clauses; ++i)
  {
  	set<int> temp_clause;
  	string new_line;
  	int num;
  	getline(ifile, new_line, '\n');
  	stringstream sa(new_line);
  	while(sa >> num)
  	{
  		if(num == 0)
  		{
  			break;
  		}
  		else
  		{
  			temp_clause.insert(num);
  		}
  	}

  	all_clauses.insert(make_pair(i, temp_clause));
  }


  AVLTree<int, int> sol;
  for(int i = 1; i < num_vars+1; ++i)
  {	
  	sol.insert(make_pair(i, -1));
  }

  ofstream ofile(argv[2]);

  if(sol.empty())
  {
  	cerr << "Invalid input variables." << endl;
  }
  else
  {
  	if(!solveHelper(sol, all_clauses, 1))
  	{
  		ofile << "No solution" << endl;
  		printSolution(sol, ofile);
  	}
  	else
  	{
  		printSolution(sol, ofile);
  	}
  }

  return 0;
}


size_t check_correct_clause(AVLTree<int, int>& sol, map<int, set<int> >& all_clauses)
{
	unsigned int num_correct_clauses = 0;
	map<int, set<int> >::iterator it;
	for(it = all_clauses.begin(); it != all_clauses.end(); ++it)
	{
		set<int> temp_clause = it->second;
		set<int>::iterator jt;
		for(jt = temp_clause.begin(); jt != temp_clause.end(); ++jt)
		{
			int var = abs(*jt);
			AVLTree<int, int>::iterator ft = sol.find(var);
			int val = ft->second;

			if(*jt < 0 && val == 0)
			{
				num_correct_clauses++;
				break;
			}
			else if(*jt > 0 && val == 1)
			{
				num_correct_clauses++;
				break;
			}
		}
	}
	return num_correct_clauses;
}


bool solveHelper(AVLTree<int, int>& sol, map<int, set<int> >& all_clauses, size_t curr_var)
{

	if(check_correct_clause(sol, all_clauses) == all_clauses.size())
	{
		return true;
	}
	else{
		for(int i = 0; i < 2; ++i)
		{
			AVLTree<int, int>::iterator it = sol.find(curr_var);
			int prev_val = it->second;
			sol.insert(make_pair(it->first, i));

			if(isValid(sol, all_clauses, curr_var))
			{
				if(solveHelper(sol, all_clauses, curr_var+1))
				{
					return true;
				} 
			}
			sol.insert(make_pair(it->first, prev_val));

		}
		return false;
	}
}


bool isValid(AVLTree<int, int>& sol, map<int, set<int> >& all_clauses, size_t curr_var)
{
	map<int, set<int> >::iterator pt;
	for(pt = all_clauses.begin(); pt != all_clauses.end(); ++pt)
	{
		set<int> temp_clause = pt->second;
		set<int>::iterator it;
		bool clause_val = false;
		for(it = temp_clause.begin(); it != temp_clause.end(); ++it)
		{
			int var = abs(*it);
			AVLTree<int, int>::iterator ht = sol.find(var);
			int correspond_val = ht->second;
			if(correspond_val == -1)
			{
				clause_val = true;
				break;
			}
			else if(*it < 0 && correspond_val == 0)
			{
				clause_val = true;
				break;
			}
			else if(*it > 0 && correspond_val == 1)
			{
				clause_val = true;
				break;
			}
		}

		if(clause_val == false)
		{
			return false;
		}
	}
	return true;
}

void printSolution(AVLTree<int, int>& sol, ofstream& ofile)
{
	AVLTree<int, int>::iterator jt;
	int i = 1;
	for(jt = sol.begin(); jt != sol.end(); ++jt)
	{
		if(jt->second != -1)
		{
			ofile << i << " = " << jt->second << endl;
			i++;
		}
	}
}