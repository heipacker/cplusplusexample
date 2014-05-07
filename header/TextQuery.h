/*
 * TextQuery.h
 *
 *  Created on: 2014-5-7
 *      Author: Administrator
 */

#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

class TextQuery {
public :
	typedef std::vector<std::string>::size_type line_no;

	void read_file(std::ifstream &is) {
		store_file(is);
		build_map();
	}

	std::set<line_no> run_query(const std::string&) const;
	std::string text_line(line_no) const;
private :
	void store_file(std::ifstream&);
	void build_map();

	std::vector<std::string> lines_of_text;
	std::map<std::string, std::set<line_no> > word_map;

	static std::string cleanup_str(const std::string&);
};

std::string make_plural(std::size_t ctr, const std::string &word, const std::string &ending);
std::ifstream& open_file(std::ifstream &in, const std::string &file);
void print_results(const std::set<TextQuery::line_no>& locs, const std::string &sought, const TextQuery &file);

#endif /* TEXTQUERY_H_ */
