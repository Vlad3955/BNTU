unit MatFunc;

interface
  Function Tg(x: extended) : extended;  //������� ��� ���������� ��������
  Function Ch(x: extended) : extended;  //������� ��� ���������� ����������������
                                                                //������
  Function Sin2(x: extended) : extended;//������� ��� ���������� �������� ������
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
