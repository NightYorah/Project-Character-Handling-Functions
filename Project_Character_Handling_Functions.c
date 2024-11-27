#include<stdio.h>
int x;
char sentence[100];	
int checkBlank(char *sent)
{
	int count=0;
	for(x=0;*sent!='\0';x++)
	{
		if(*sent==' ')
		{
			count++;
		}else
		{
			return 0;
		}
		sent++;
	}
	if(count>0)
		{
			return 1;
		}
}
int checkDigit(char *sent)
{
	int none=0;
	for(x=0;*sent!='\0';x++)
	{
		if(*sent<'0'||*sent>'9')
		{
			return 0;
		}else
		{
			none++;
		}
		sent++;
	}
	if(none>0)
	{
		return 1;
	}
}
int checkAlpha(char *sent)
{
	int alphacount=0;
	for(x=0;*sent!='\0';x++)
	{
		if((*sent>='a'&&*sent<='z')||(*sent>='A'&&*sent<='Z'))
		{
			alphacount++;
		}else
		{
			return 0;
		}
		sent++;
	}
	if(alphacount>0)
	{
		return 1;
	}
}
int checkAlphaDigit(char *sent)
{
	int alphacount=0;
	for(x=0;*sent!='\0';x++)
	{
		if((*sent>='a'&&*sent<='z')&&(*sent>='A'&&*sent<='Z'))
		{
			alphacount++;
		}else if(*sent<'0'||*sent>'9')
		{
			alphacount++;
		}else
		{
			return 0;
		}
		sent++;
	}
	if(alphacount>0)
	{
		return 1;
	}
}
int checkHexDigit(char *sent)
{
	int hex=0;
	for(x=0;*sent!='\0';x++)
	{
		if((*sent>='0'&&*sent<='9')||(*sent>='A'&&*sent<='F'))
		{
	        return 1;
		}else
		{
			return 0;
		}
	    sent++;
	}
}
int checkLower(char *sent)
{
	int low=0;
	for(x=0;*sent!='\0';x++)
	{
		if(*sent>='a'&&*sent<='z')
		{
			low++;
		}else
		{
			return 0;
		}
		sent++;
	}
	if(low>0)
	{
		return 1;
	}
}
int checkUpper(char *sent)
{
	int high=0;
	for(x=0;*sent!='\0';x++)
	{
		if(*sent>='A'&&*sent<='Z')
		{
			high++;
		}else
		{
			return 0;
		}
		sent++;
	}
	if(high>0)
	{
		return 1;
	}
}
void turnUpper(char *sent)
{
	for(x=0;*sent!='\0';x++)
	{
		if(*sent>='a'&&*sent<='z')
		{
			*sent-=32;
		}
		sent++;
	}
}
void turnLower(char *sent)
{
	for(x=0;*sent!='\0';x++)
	{
		if(*sent>='A'&&*sent<='Z')
		{
			*sent+=32;
		}
		sent++;
	}
}
int checkSpace(char *sent)
{
	int space=0;
	for(x=0;*sent!='\0';x++)
	{
		if(*sent==' '||*sent=='\n'||*sent=='\f'||*sent=='\r'||*sent=='\t'||*sent=='\v')
		{
			space++;
		}else
		{
			return 0;
		}
		sent++;
	}
	if(space>0)
	{
		return 1;
	}
}
int checkControl(char *sent)
{
	int control=0;
	for(x=0;*sent!='\0';x++)
	{
		if(*sent=='\a'||*sent=='\b'||*sent=='\r'||*sent=='\n'||*sent=='\f'||*sent=='\t'||*sent=='\v')
		{
			control++;
		}else
		{
			control=0;
		}
		sent++;
	}
	if(control>0)
	{
		return 1;
	}else
	{
		return 0;
	}
}
int checkPunct(char *sent)
{
	int punct=0;
	for(x=0;*sent!='\0';x++)
	{
		if(checkAlpha(sent)==1||checkSpace(sent)==1||checkDigit(sent)==1)
		{
			return 0;
		}else
		{
			punct++;
		}
		sent++;
	}
	if(punct>0)
	{
		return 1;
	}
}
int checkPrint(char *sent)
{
	int print=0;
	for(x=0;*sent!='\0';x++)
	{
		if(checkAlphaDigit(sent) == 1||checkSpace(sent)==1||checkPunct(sent) == 1)
	    {
		    print++;
	    }else
	    {
		    print=0;
	    }
	    sent++;
	}
	if(print>0)
	{
		return 1;
    }
}
int checkGraph(char *sent)
{
	int graph=0;
	for(x=0;*sent!='\0';x++)
	{
		 if(checkAlphaDigit(sent)==1||checkPunct(sent)==1)
	    {
		    graph++;
	    }else
	    {
		    graph=0;
	    }
	    sent++;
	}
	if(graph>0)
	{
		return 1;
	}else
	{
		return 0;
	}
}
void Menu()
{
	int choice;
	printf("Enter any input to check:");
	fgets(sentence, sizeof(sentence), stdin);
	printf("Select a Function: \n\n1.CheckBlank\n\n2.CheckDigit\n\n3.CheckAlpha\n\n4.CheckAlphaDigit\n\n5.CheckHexDigit\n\n6.CheckLower\n\n7.CheckUpper\n\n8.TurnLower\n\n9.TurnUpper\n\n10.CheckSpace\n\n11.CheckControl\n\n12.CheckPunct\n\n13.CheckPrint\n\n14.CheckGraph");
	printf("\n\nChoice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			{
				checkBlank(sentence);
				break;
			}
		case 2:
			{
				checkDigit(sentence);
				break;
			}
		case 3:
			{
				checkAlpha(sentence);
				break;
			}
		case 4:
			{
				checkAlphaDigit(sentence);
				break;
			}
		case 5:
			{
				checkHexDigit(sentence);
				break;
			}
		case 6:
			{
				checkLower(sentence);
				break;
			}
		case 7:
			{
				checkUpper(sentence);
				break;
			}
		case 8:
			{
				turnLower(sentence);
				break;
			}
		case 9:
			{
				turnUpper(sentence);
				break;
			}
		case 10:
			{
				checkSpace(sentence);
				break;
			}
		case 11:
			{
				checkControl(sentence);
				break;
			}
		case 12:
			{
				checkPunct(sentence);
				break;
			}
		case 13:
			{
				checkPrint(sentence);
				break;
			}
		case 14:
			{
				checkGraph(sentence);
				break;
			}
		default:
			{
				printf("Enter a valid choice:");
				Menu();
				break;
			}
	}
}
main()
{
	Menu();
    printf("Your sentence: %s", sentence);
    return 0;
}
