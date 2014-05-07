/*
 * TextQuery.cpp
 *
 *  Created on: 2014-5-7
 *      Author: Administrator
 */
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "../header/TextQuery.h"

using namespace std;

void TextQuery::store_file(ifstream &is){
	string textline;
	while(getline(is, textline)){
		lines_of_text.push_back(textline);
	}
}

void TextQuery::build_map(){
	for(line_no line_num = 0; line_num != lines_of_text.size(); ++line_num){
		istringstream line(lines_of_text[line_num]);
		string word;
		while( line >> word) {
			word_map[cleanup_str(word)].insert(line_num);
		}
	}
}

string TextQuery::text_line(line_no line) const {
	if(line < lines_of_text.size()){
		return lines_of_text[line];
	}
	throw out_of_range("line number out of range.");
}

set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const {
	map<string, set<line_no> >::const_iterator loc = word_map.find(query_word);
	if(loc == word_map.end()){
		return set<line_no>();
	} else{
		return loc->second;
	}
}

string TextQuery::cleanup_str(const string &word){
	string rtn;
	for( string::const_iterator it = word.begin(); it != word.end(); ++it){
		if(!ispunct(*it)){
			rtn += tolower(*it);
		}
	}
	return rtn;
}

std::string make_plural(std::size_t ctr, const std::string &word, const std::string &ending){
	return (ctr == 1) ? word : word + ending;
}

ifstream& open_file(ifstream &in, const string &file){
	in.close();
	in.clear();

	in.open(file.c_str());
	return in;
}

void print_results(const std::set<TextQuery::line_no>& locs, const std::string &sought, const TextQuery &file){
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs " << size << " " << make_plural(size, "time", "s") << endl;

	line_nums::const_iterator it = locs.begin();
	for( ; it != locs.end(); ++it){
		cout << "\t(line " << (*it) + 1 << ") " << file.text_line(*it) << endl;
	}
}

