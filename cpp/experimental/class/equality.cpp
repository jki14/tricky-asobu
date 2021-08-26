struct C {
public:
  int x, y;
};

bool operator==(C const& lhs, C const& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

int main() {
  C lhs, rhs;
  lhs.x = 11;
  lhs.y = 14;
  rhs.x = 11;
  rhs.y = 14;
  return !(lhs == rhs);
}
