// AddExpression.java

public class AddExpression implements Expression {
  private Expression left, right;

  public AddExpression(Expression left, Expression right) {
    this.left = left;
    this.right = right;
  }

  @Override
  public int interpret() {
    return left.interpret() + right.interpret();
  }
}
