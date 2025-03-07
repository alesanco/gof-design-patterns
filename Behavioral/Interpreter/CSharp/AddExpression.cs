// AddExpression.cs

public class AddExpression : IExpression {
  private readonly IExpression _left, _right;

  public AddExpression(IExpression left, IExpression right) {
    _left = left;
    _right = right;
  }

  public int Interpret() {
    return _left.Interpret() + _right.Interpret();
  }
}
