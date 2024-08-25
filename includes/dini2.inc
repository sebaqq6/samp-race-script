/*
    [INC] dini2 v1.5 by Maku
        Utworzono i opublikowano: 24.08.2013r.
        Ostatnia modyfikacja: 30.06.2014r.
        
        Stworzono dla pawno.pl z myślą o optymalizacji skryptów początkujących pawnerów.
*/

#if defined _dini2_included
  #endinput
#endif
#define _dini2_included

/*
	native dini_Exists(filename[]);
	native dini_Remove(filename[]);
	native dini_Create(filename[]);
	native dini_Set(filename[], key[], value[]);
	native dini_IntSet(filename[], key[], value);
	native dini_Int(filename[], key[]);
	native dini_FloatSet(filename[], key[], Float:value);
	native dini_Float(filename[], key[]);
	native dini_BoolSet(filename[], key[], bool:value);
	native dini_Bool(filename[], key[]);
	native dini_Unset(filename[], key[]);
	native dini_Get(filename[], key[]);
	native dini_Isset(filename[], key[]);
*/

/*
	[PLUGIN] Y_Files by Y_Less
*/
native ffind(const pattern[], filename[], len, &idx);
native frename(const oldname[], const newname[]);
native dfind(const pattern[], filename[], len, &idx);
native dcreate(const name[]);
native drename(const oldname[], const newname[]);

#if !defined DINI_MAX_STRING
	#define DINI_MAX_STRING (256)
#endif
#define DINI_MAX_STRING (256)
#define DINI_TMP_FILE "dini.tempfile"

#if !defined DINI_IGNORECASE 
	#define DINI_IGNORECASE true
#endif

static dini_int;
static dini_finded;
static File:file_handle_a;
static File:file_handle_b;
static dini_string[DINI_MAX_STRING];

#define dini_Exists(%0) fexist(%0)
#define dini_Remove(%0) fremove(%0)

stock dini_Create(filename[]) 
{
	if (fexist(filename)) return false;

	file_handle_a = fopen(filename, io_write);
	if (file_handle_a) 
	{
		fclose(file_handle_a);
		return true;
	}
	return false;
}

stock dini_Set(filename[],key[],value[])
{
	dini_int = strlen(key);
	if(dini_int == 0 || dini_int + strlen(value) + 2 > DINI_MAX_STRING) return false;
	
	if(fexist(DINI_TMP_FILE)) fremove(DINI_TMP_FILE); 
	
	file_handle_b = fopen(filename, io_write);
	if(!file_handle_b) return false;
	file_handle_a = fopen(filename, io_read);
	dini_finded = 0;
	
	if(file_handle_a)
	{	
		while(fread(file_handle_a, dini_string)) 
		{
			if(!dini_finded && dini_string[dini_int] == '=' && !strcmp(dini_string, key, DINI_IGNORECASE, dini_int))
			{
				format(dini_string, sizeof(dini_string), "%s=%s\r\n", key, value);
				dini_finded = 1;
			}
			fwrite(file_handle_b, dini_string);
			fwrite(file_handle_b, "\r\n");
		}	
		if(!dini_finded) 
		{
			format(dini_string, sizeof(dini_string), "%s=%s\r\n", key, value);
			fwrite(file_handle_b, dini_string);
		}
		fclose(file_handle_a);
		fclose(file_handle_b);

		frename(DINI_TMP_FILE, filename);
		return true;	
	}
	
	fclose(file_handle_b);
	file_handle_b = fopen(filename, io_write);
	
	if(!file_handle_b) return false;
	
	format(dini_string, sizeof(dini_string), "%s=%s\r\n", key, value);
	fwrite(file_handle_b, dini_string);
	return true;
}


stock dini_IntSet(filename[], key[], value) 
{
	dini_int = strlen(key);
	if(dini_int == 0 || dini_int + 13 > DINI_MAX_STRING) return false;
	
	if(fexist(DINI_TMP_FILE)) fremove(DINI_TMP_FILE); 
	
	file_handle_b = fopen(filename, io_write);
	if(!file_handle_b) return false;
	file_handle_a = fopen(filename, io_read);
	dini_finded = 0;
	
	if(file_handle_a)
	{	
		while(fread(file_handle_a, dini_string)) 
		{
			if(!dini_finded && dini_string[dini_int] == '=' && !strcmp(dini_string, key, DINI_IGNORECASE, dini_int))
			{
				format(dini_string, sizeof(dini_string), "%s=%d\r\n", key, value);
				dini_finded = 1;
			}
			fwrite(file_handle_b, dini_string);
			fwrite(file_handle_b, "\r\n");
		}	
		if(!dini_finded) 
		{
			format(dini_string, sizeof(dini_string), "%s=%d\r\n", key, value);
			fwrite(file_handle_b, dini_string);
		}
		fclose(file_handle_a);
		fclose(file_handle_b);

		frename(DINI_TMP_FILE, filename);
		return true;	
	}
	
	fclose(file_handle_b);
	file_handle_b = fopen(filename, io_write);
	
	if(!file_handle_b) return false;
	
	format(dini_string, sizeof(dini_string), "%s=%d\r\n", key, value);
	fwrite(file_handle_b, dini_string);
	return true;
}
#define dini_Int(%0,%1) strval(dini_Get(%0,%1))

stock dini_FloatSet(filename[], key[], Float:value) 
{
	dini_int = strlen(key);
	if(dini_int == 0 || dini_int + 13 > DINI_MAX_STRING) return false;
	
	if(fexist(DINI_TMP_FILE)) fremove(DINI_TMP_FILE); 
	
	file_handle_b = fopen(filename, io_write);
	if(!file_handle_b) return false;
	file_handle_a = fopen(filename, io_read);
	dini_finded = 0;
	
	if(file_handle_a)
	{	
		while(fread(file_handle_a, dini_string)) 
		{
			if(!dini_finded && dini_string[dini_int] == '=' && !strcmp(dini_string, key, DINI_IGNORECASE, dini_int))
			{
				format(dini_string, sizeof(dini_string), "%s=%f\r\n", key, value);
				dini_finded = 1;
			}
			fwrite(file_handle_b, dini_string);
			fwrite(file_handle_b, "\r\n");
		}	
		if(!dini_finded) 
		{
			format(dini_string, sizeof(dini_string), "%s=%f\r\n", key, value);
			fwrite(file_handle_b, dini_string);
		}
		fclose(file_handle_a);
		fclose(file_handle_b);

		frename(DINI_TMP_FILE, filename);
		return true;	
	}
	
	fclose(file_handle_b);
	file_handle_b = fopen(filename, io_write);
	
	if(!file_handle_b) return false;
	
	format(dini_string, sizeof(dini_string), "%s=%f\r\n", key, value);
	fwrite(file_handle_b, dini_string);
	return true;
}
#define dini_Float(%0,%1) floatstr(dini_Get(%0,%1))

stock dini_BoolSet(filename[], key[], value)
{
	if(value) 
	{
		return dini_IntSet(filename, key, "1");
	}
	return dini_IntSet(filename, key, "0");
}
#define dini_Bool(%0,%1) bool:strval(dini_Get(%0, %1))

stock dini_Unset(filename[], key[]) 
{
	dini_int = strlen(key);
	if(dini_int == 0 || dini_int + 2 > DINI_MAX_STRING) return false;
	
	if(fexist(DINI_TMP_FILE)) fremove(DINI_TMP_FILE); 
	
	file_handle_a = fopen(filename, io_read);
	if(!file_handle_a) return false;
	
	file_handle_b = fopen(filename, io_write);
	if(!file_handle_b) return false;
	
	dini_finded = 0;
	
	while(fread(file_handle_a, dini_string)) 
	{
		if(!dini_finded && dini_string[dini_int] == '=' && !strcmp(dini_string, key, DINI_IGNORECASE, dini_int))
		{
			dini_finded = 1;
		}
		if(dini_finded != 1)
		{
			fwrite(file_handle_b, dini_string);
			fwrite(file_handle_b, "\r\n");
		}
		if(dini_finded == 1) dini_finded = 2;
	}
	fclose(file_handle_a);
	fclose(file_handle_b);

	frename(DINI_TMP_FILE, filename);
	return true;
}

stock dini_Get(filename[], key[]) 
{
	dini_string[0] = EOS;
	dini_int = strlen(key);
	if (dini_int == 0 || dini_int + 2 > DINI_MAX_STRING) return dini_string;
	
	file_handle_a = fopen(filename,io_read);
	if (!file_handle_a) return dini_string;
	
	while(fread(file_handle_a,dini_string)) 
	{
		if(dini_string[dini_int] == '=' && !strcmp(dini_string, key, DINI_IGNORECASE, dini_int)) 
		{
			strmid(dini_string, dini_string, dini_int + 1, strlen(dini_string), DINI_MAX_STRING);
			fclose(file_handle_a);
			return dini_string;
		}
	}
	fclose(file_handle_a);
	dini_string[0] = EOS;
	return dini_string;
}


stock dini_Isset(filename[], key[]) 
{
	dini_int = strlen(key);
	if (dini_int == 0 || dini_int + 2 > DINI_MAX_STRING) return false;
	
	file_handle_a = fopen(filename, io_read);
	if (!file_handle_a) return false;
	
	while (fread(file_handle_a, dini_string)) 
	{
		if (dini_string[dini_int] == '=' &&  !strcmp(dini_string, key, DINI_IGNORECASE, dini_int))
		{
			fclose(file_handle_a);
			return true;
		}
	}
	fclose(file_handle_a);
	return false;
}