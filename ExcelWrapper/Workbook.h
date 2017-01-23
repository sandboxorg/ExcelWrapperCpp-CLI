#pragma once
using namespace Microsoft::Office::Interop::Excel;
using namespace System::Collections::Generic;
using namespace System;
namespace Excel = Microsoft::Office::Interop::Excel;
#include <map>
#include <memory>
#include "Worksheet.h"

namespace WorkbookWrapper{
	public ref class WorkbookSheetsWrapper{
	public:
		WorkbookSheetsWrapper(Excel::Workbook^ workbook);
		WorksheetWrapper::Worksheet^ WorkbookWrapper::WorkbookSheetsWrapper::operator [](String^ worksheetName);
		WorksheetWrapper::Worksheet^ WorkbookWrapper::WorkbookSheetsWrapper::operator [](int worksheetNumber);
	private:
		Excel::Workbook^ wrappedWorkbook;
	};

	public ref class Workbook
	{
	public:
		Workbook(Excel::Application^ xl, System::String^ filePath);
		!Workbook();
		~Workbook();
		WorkbookWrapper::WorkbookSheetsWrapper^ Sheets;
	private:
		Excel::Workbook^ wrappedWorkbook;
		Dictionary<String^, WorksheetWrapper::Worksheet^> worksheetNameDict;
		Dictionary<int, WorksheetWrapper::Worksheet^> worksheetIntDict;
	};
}
