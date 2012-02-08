								//Mohammad Motiur Rahman
								//I.D-082707040
								//CSE-325

Procedure InsertionSort(numbers : Array of Integer; size : Integer);
Var i, j,k, index : Integer;


Begin
 For i := 2 to size-1 do
  Begin
   index := numbers[i];
   j := i;
   While ((j > 1) AND (numbers[j-1] > index)) do
    Begin
     numbers[j] := numbers[j-1];
     j := j - 1;
    End;
   numbers[j] := index;
  End;
  For k := 2 to size-1 do
    Begin
	  Writeln('Value of:',k,'is ',numbers[k])
	End;
End;


var	i	: Integer;
var	myArr: Array[1..200] of Integer;
var k: Integer;
	


Begin
	k := 200;
	For i := 1 to 200 do
		Begin
			myArr[i] := 200-i;
		End;

	InsertionSort(myArr,k);

End.