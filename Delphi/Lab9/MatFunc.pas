unit MatFunc;

interface
  Function Tg(x: extended) : extended;  //Функция для вычисления тангенса
  Function Ch(x: extended) : extended;  //Функция для вычисления гиперболического
                                                                //синуса
  Function Sin2(x: extended) : extended;//Функция для вычисления квадрата синуса
implementation
  Function Tg(x: extended) : extended;
  begin
    Result := sin(x)/cos(x);
  end;

  Function Ch(x: extended) : extended;
  begin
    Result := (exp(x)-exp(-x))/2;
  end;

  Function Sin2(x: extended) : extended;
  begin
    Result := sqr(sin(x));
  end;
end.
