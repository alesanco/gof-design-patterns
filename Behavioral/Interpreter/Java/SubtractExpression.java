// SubtractExpression.java

public class SubtractExpression implements Expression {
  private Expression left, right;

  public SubtractExpression(Expression left, Expression right) {
    this.left = left;
    this.right = right;
  }

  @Override
  public int interpret() {
    return left.interpret() - right.interpret();
  }
}
