// SubtractExpression.cs

public class SubtractExpression : IExpression {
  private readonly IExpression _left, _right;

  public SubtractExpression(IExpression left, IExpression right) {
    _left = left;
    _right = right;
  }

  public int Interpret() {
    return _left.Interpret() - _right.Interpret();
  }
}
