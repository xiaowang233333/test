DWORD dwFileSize = 0;
 
	WIN32_FIND_DATA FileInfo;
 
	ZeroMemory(&FileInfo,sizeof(WIN32_FIND_DATA));
 
	HANDLE hFind = INVALID_HANDLE_VALUE;
 
	hFind = FindFirstFile("D:\\12123.jpg",&FileInfo); 
 
	if(hFind != INVALID_HANDLE_VALUE) 
	{
		dwFileSize = FileInfo.nFileSizeLow ;
	}
 
	FindClose(hFind);
 
	BYTE* buffer = new BYTE[dwFileSize];
 
	if (buffer == NULL)
	{
		cout<<"Create buffer error !"<<endl;
 
		return 0;
	}
 
	ZeroMemory(buffer,dwFileSize);
 
	FILE *f = NULL;
 
	fopen_s(&f,"D:\\12123.jpg","rb");
 
	if (f == NULL)
	{
		delete [] buffer;
 
		buffer = NULL;
 
		cout<<"fopen_s error -1 !"<<endl;
 
		return 0;
	} 
	else
	{
		fread(buffer,dwFileSize,1,f);
	}
 
	fclose(f);
 
	f = NULL;
 
	fopen_s(&f,"D:\\333.jpg","wb");
 
	if (f == NULL)
	{
		cout<<"fopen_s error -2 !"<<endl;
 
		return 0;
	}
 
	if (fwrite(buffer,dwFileSize,1,f) < 1){
		
		cout<<"fwrite error !"<<endl;
	}
 
	fclose(f);
 
	f = NULL;



    DWORD dwFileSize = 0;
 
	BYTE* buffer = NULL;
 
	HANDLE hFile = INVALID_HANDLE_VALUE;
 
	hFile = CreateFile("D:\\12123.jpg",GENERIC_READ,
		               FILE_SHARE_READ,NULL,OPEN_EXISTING,
					   FILE_ATTRIBUTE_NORMAL,NULL);
 
	if (hFile == INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
 
		cout<<"Create File Failed !"<<endl;
 
		return 0;
	} 
	else
	{
		dwFileSize = GetFileSize(hFile,NULL);
 
		//LARGE_INTEGER lFileSize;
 
		//GetFileSizeEx(hFile,&lFileSize);//若文件长度超过0xFFFFFFFF，使用GetFileSizeEx。
 
		cout<<"文件大小 "<<dwFileSize<<endl;
 
		buffer = new BYTE[dwFileSize];
 
		if (buffer == NULL)
		{
			cout<<"Create buffer error !"<<endl;
	        
	      return 0;
		}
 
		ZeroMemory(buffer,dwFileSize);
 
		DWORD dwReadSize = 0,dwReadTotal = 0;
 
		while (dwReadTotal < dwFileSize)
		{
			ReadFile(hFile,buffer + dwReadTotal,dwFileSize - dwReadSize,&dwReadSize,NULL);
 
			dwReadTotal += dwReadSize;
		}
 
		cout<<"总共读取的文件大小 "<<dwReadTotal<<endl;
	}
	
	hFile = CreateFile("D:\\222.jpg",GENERIC_WRITE,0,NULL,               
		CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
 
	if (hFile == INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
 
		cout<<"Create File Failed -2 !"<<endl;
 
		delete []buffer;
 
		buffer = NULL;
 
		return 0;
	} 
	else
	{
		DWORD dwWriteTotal = 0,dwWriteSize = 0;
 
		while (dwWriteTotal < dwFileSize)
		{
			WriteFile(hFile,buffer + dwWriteTotal,dwFileSize,&dwWriteSize,NULL);
 
			dwWriteTotal += dwWriteSize;
		}
	}
 
	delete []buffer;
 

————————————————
版权声明：本文为CSDN博主「小米的修行之路」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u012372584/article/details/77619448