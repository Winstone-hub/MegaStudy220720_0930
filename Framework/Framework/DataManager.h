#pragma once
#include "Headers.h"
#include <sstream>
#include <istream>

class DataManager
{
private:
	static list<string> filePaths;
public:
	static void saveData(string fileName)
	{
		// ** 현재 프로젝트 파일의 위치를 받아온다.
		istringstream iss(__FILE__);

		// ** 경로들을 잘라내기 위해 임시로 사용될 문자열 공간.
		string buffer = "";

		// ** 잘라낸 문자열을 잠시 보관하기 위한 공간.
		vector<string> temp;

		// ** [\] 를 기준으로 문자열을 잘라냄. 
		while (getline(iss, buffer, '\\'))
			temp.push_back(buffer);

		// ** 문자열을 잘라냈다면 마지막 2개를 삭제.
		temp.pop_back(); // ** 현재 파일 [DataManager.h] 가 삭제된다.
		temp.pop_back(); // ** [DataManager.h] 가 포함되어있는 폴더 이름이 삭제된다.

		// ** 삭제가 완료 되었다면 다시 결합하기 위한 임시의 공간을 생성.
		string path = "";

		// ** 경로를 다시 재 결합 시킨다.
		for (vector<string>::iterator iter = temp.begin(); iter != temp.end(); ++iter)
			path += (*iter) + "\\"; 

		
		// ** 리소스가 있는 위치로 Path 를 만든다.
		filePaths.push_back(path + "Resources\\" + fileName);
	}

	static void loadData()
	{
		for (list<string>::iterator iter = filePaths.begin(); iter != filePaths.end(); ++iter)
			cout << (*iter) << endl;
	}
	
};


list<string> DataManager::filePaths;